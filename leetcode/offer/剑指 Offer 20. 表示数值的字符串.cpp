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