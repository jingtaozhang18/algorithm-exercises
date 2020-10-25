// https://leetcode-cn.com/problems/basic-calculator/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int readnum(string &s, int &i, int &len, bool flag){
        int num=0;
        while(s[i]>='0' && s[i]<='9' && i<len){
            num*=10;
            num+=s[i]-'0';
            i=i+1;
        }
        return flag?num:-1*num;
    }
    int calc(string &s, int& i, int &len){
        int ans=0;
        bool flag=true;
        for(;i<len;++i){
            if(s[i]=='+') flag=true;
            else if(s[i]=='-') flag=false;
            else if(s[i]>='0' && s[i]<='9') ans+=readnum(s,i,len,flag),--i;
            else if(s[i]=='(') ans+=flag?calc(s,++i,len):-1*calc(s,++i,len);
            else if(s[i]==')') return ans;
        }
        return ans;
    }
    int calculate(string s) {
        int i=0,len=s.size();
        return calc(s,i,len);
    }
};