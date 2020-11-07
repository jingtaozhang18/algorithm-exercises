// https://leetcode-cn.com/problems/ba-zi-fu-chuan-zhuan-huan-cheng-zheng-shu-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strToInt(string str) {
        int i=0;
        bool flag=true;
        bool hread=false;
        int a=INT_MIN/10, b=-1*(INT_MIN%10), v=0, t; // 负数的范围更大
        while(i<str.size()&&str[i]==' ') ++i;
        if(str[i]=='+')flag=true,++i;
        else if(str[i]=='-')flag=false,++i;
        for(;i<str.size()&&str[i]>='0'&&str[i]<='9';++i){
            hread=true, t = str[i]-'0';
            if(v<a) return flag?INT_MAX:INT_MIN;
            else if(v==a&&t>b) return flag?INT_MAX:INT_MIN;
            else v*=10,v-=t;
        }
        if(!hread) return 0; // 没有读取到合法的数字
        if(flag){
            if(v==INT_MIN) return INT_MAX;
            else return -1*v;
        }else{
            return v;
        }
    }
};