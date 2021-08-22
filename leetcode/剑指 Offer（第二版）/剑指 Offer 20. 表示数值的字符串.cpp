// https://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int flag=2;
        for(char c: s){
            if(flag==2){ // 起始空格位
                if(c==' ') flag=2;
                else if(c=='+'||c=='-') flag=3;
                else if(c>='0'&&c<='9') flag=4;
                else if(c=='.') flag=5;
                else return false;
            } else if(flag==3){ // 整数部分符号
                if(c=='.') flag=5;
                else if(c>='0'&&c<='9') flag=4;
                else return false;
            } else if(flag==4){ // 整数部分
                if(c=='.') flag=6;
                else if (c>='0'&&c<='9') flag=4;
                else if(c=='e'||c=='E') flag=8;
                else if(c==' ') flag=11;
                else return false;
            } else if(flag==5){ // 无整数小数点
                if(c>='0'&&c<='9') flag=7;
                else return false;
            } else if(flag==6){ // 有整数小数点
                if(c>='0'&&c<='9') flag=7;
                else if(c=='e'||c=='E') flag=8;
                else if(c==' ') flag=11;
                else return false;
            } else if(flag==7){ // 小数部分
                if(c>='0'&&c<='9') flag=7;
                else if(c=='e'||c=='E') flag=8;
                else if(c==' ') flag=11;
                else return false;
            } else if(flag==8){
                if(c=='+'||c=='-') flag=9;
                else if(c>='0'&&c<='9') flag=10;
                else return false;
            } else if(flag==9){
                if(c>='0'&&c<='9') flag=10;
                else return false;
            } else if(flag==10){
                if(c>='0'&&c<='9') flag=10;
                else if(c==' ') flag=11;
                else return false;
            } else if(flag==11){
                if(c==' ') flag=11;
                else return false;
            } else return false;
        }
        if(flag==4||flag==6||flag==7||flag==10||flag==11) return true;
        else return false;
    }
};

// 复习
class Solution {
public:
    bool isNumber(string s) {
        int flag=0;
        for(auto &c:s){
            if(flag==0){ // init
                if(c=='+'||c=='-') flag=1;
                else if(isdigit(c)) flag=2;
                else if(c=='.') flag=8;
                else if(c==' ') flag=0;
                else return false;
            }else if(flag==1){ // +/-之后
                if(isdigit(c)) flag=2;
                else if(c=='.') flag=8;
                else return false;
            }else if (flag==2){ // 小数点左边数字
                if(isdigit(c)) flag=2;
                else if(c=='.') flag=3;
                else if(c=='e'||c=='E') flag=5;
                else if(c==' ') flag=9;
                else return false;
            }else if(flag==3){ // 小数点（左边有数字）
                if(isdigit(c)) flag=4;
                else if(c=='e'||c=='E') flag=5;
                else if(c==' ') flag=9;
                else return false;
            }else if(flag==4){ // 小数点后数字部分
                if(isdigit(c)) flag=4;
                else if(c=='e'||c=='E') flag=5;
                else if(c==' ') flag=9;
                else return false;
            }else if(flag==5){ // E/e之后
                if(c=='+'||c=='-') flag=6;
                else if(isdigit(c)) flag=7;
                else return false;
            }else if(flag==6){ // E/e +/-之后
                if(isdigit(c)) flag=7;
                else return false;
            }else if(flag==7){ // E/e +/-数字部分
                if(isdigit(c)) flag=7;
                else if(c==' ') flag=9;
                else return false;
            }else if(flag==8){ // 小数点（左侧无数字）
                if(isdigit(c)) flag=4;
                else return false;
            }else if(flag==9){ // 末尾空格
                if(c==' ') flag=9;
                else return false;
            }
        }
        if(flag==2||flag==3||flag==4||flag==7||flag==9) return true;
        return false;
    }
};