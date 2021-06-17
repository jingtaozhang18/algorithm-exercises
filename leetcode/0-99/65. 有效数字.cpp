// https://leetcode-cn.com/problems/valid-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int flag=0;
        for(auto &c:s){
            if(flag==0){
                if(c=='+'||c=='-') flag=1;
                else if(isdigit(c)) flag=2;
                else if(c=='.') flag=8;
                else return false;
            }else if(flag==1){
                if(isdigit(c)) flag=2;
                else if(c=='.') flag=8;
                else return false;
            }else if (flag==2){
                if(isdigit(c)) flag=2;
                else if(c=='.') flag=3;
                else if(c=='e'||c=='E') flag=5;
                else return false;
            }else if(flag==3){
                if(isdigit(c)) flag=4;
                else if(c=='e'||c=='E') flag=5;
                else return false;
            }else if(flag==4){
                if(isdigit(c)) flag=4;
                else if(c=='e'||c=='E') flag=5;
                else return false;
            }else if(flag==5){
                if(c=='+'||c=='-') flag=6;
                else if(isdigit(c)) flag=7;
                else return false;
            }else if(flag==6){
                if(isdigit(c)) flag=7;
                else return false;
            }else if(flag==7){
                if(isdigit(c)) flag=7;
                else return false;
            }else if(flag==8){
                if(isdigit(c)) flag=4;
                else return false;
            }
        }
        if(flag==2||flag==3||flag==4||flag==7) return true;
        return false;
    }
};