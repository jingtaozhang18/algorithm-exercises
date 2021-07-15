// https://www.nowcoder.com/questionTerminal/00ffd656b9604d1998e966d555005a4b
#include<string>
#include<iostream>

using namespace std;

const char *chnNumChar[] = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖"};
const char *chnUnitSection[] = {"", "万", "亿", "万亿"}; // 节权单位
const char *chnUnitChar[] = {"", "拾", "佰", "仟"}; // 节内单位

// 节内翻译操作
void SectionToChinese(unsigned int section, std::string &chnStr) {
    std::string strIns;
    int unitPos = 0;
    bool zero = true; // 保证补的0的数量是一个
    while (section > 0) {
        int v = section % 10;
        if (v == 0) {
            if ((section == 0) || !zero) {
                zero = true; /*需要补，zero的作用是确保对连续的多个，只补一个中文零*/
                chnStr.insert(0, chnNumChar[v]);
            }
        } else {
            zero = false; //至少有一个数字不是
            if (unitPos != 1 || v != 1) { // 相比于中文数字，需要添加对拾元的特殊处理
                strIns = chnNumChar[v]; //此位对应的中文数字
                strIns += chnUnitChar[unitPos]; //此位对应的中文权位
            } else {
                strIns = chnUnitChar[unitPos]; //此位对应的中文权位
            }
            chnStr.insert(0, strIns);
        }
        unitPos++; //移位
        section = section / 10;
    }
}

//num == 0需要特殊处理，直接返回"零"
void NumberToChinese(unsigned int num, std::string &chnStr) {
    int unitPos = 0;  // 节权位
    std::string strIns;
    bool needZero = false;
    while (num > 0) {
        strIns = ""; // 错误点，没有清空之前的数据
        unsigned int section = num % 10000;
        if (needZero) chnStr.insert(0, chnNumChar[0]);
        SectionToChinese(section, strIns);
        /*是否需要节权位？*/
        strIns += (section != 0) ? chnUnitSection[unitPos] : chnUnitSection[0];
        chnStr.insert(0, strIns);
        /*千位是0 需要在下一个section补零*/
        needZero = (section < 1000) && (section > 0);
        num = num / 10000;
        unitPos++;
    }
}


int main() {
    // 以万为节权进行划分

    double num;

    while (cin >> num) {
        string chnStr;
        NumberToChinese(num, chnStr);

        // 额外增加的对小数的处理
        // 错误点，需要乘以1000然后再取，否则容易失去精度
        num *= 1000;
        unsigned int a = long (num) % 1000 / 100;
        unsigned int b = long (num) % 100 / 10;
//        cout << int(num) << " " << a << " " << b << " " << to_string(num) << endl;
        if (chnStr.size()) chnStr.insert(chnStr.size(), "元");
        if (!a && !b) chnStr.insert(chnStr.size(), "整");
        else {
            if (a) {
                chnStr.insert(chnStr.size(), chnNumChar[a]);
                chnStr.insert(chnStr.size(), "角");
            }
            if (b) {
                chnStr.insert(chnStr.size(), chnNumChar[b]);
                chnStr.insert(chnStr.size(), "分");
            }

        }
        cout << "人民币" << chnStr << endl;
    }
    return 0;
}
