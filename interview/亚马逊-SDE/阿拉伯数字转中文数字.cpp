#include<string>
#include<iostream>

using namespace std;

const char *chnNumChar[] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
const char *chnUnitSection[] = {"", "万", "亿", "万亿"}; // 节权单位
const char *chnUnitChar[] = {"", "十", "百", "千"}; // 节内单位

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
            strIns = chnNumChar[v]; //此位对应的中文数字
            strIns += chnUnitChar[unitPos]; //此位对应的中文权位
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

    unsigned int num;
    cin >> num;
    string chnStr;

    NumberToChinese(num, chnStr);

    cout << chnStr << endl;

    return 0;
}
