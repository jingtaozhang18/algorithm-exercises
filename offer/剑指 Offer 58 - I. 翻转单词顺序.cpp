// https://leetcode-cn.com/problems/fan-zhuan-dan-ci-shun-xu-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(string&s, int i, int j){
        char c;
        while(i<j)c=s[i],s[i]=s[j],s[j]=c,++i,--j;
    }
    string reverseWords(string s) {
        int i,j,len=s.size()-1;
        string str="";
        bool flag=true; // true 可以有空格
        for(i=0;i<s.size()&&s[i]==' ';++i); // 走到第一非空格的位置
        while(len>=0&&s[len]==' ')len--;
        for(;i<=len;++i){
            if(s[i]!=' '){
                str+=s[i];flag=true;
            } else{
                if(flag) {
                    str+=s[i]; 
                    flag=false;
                }
                else continue;
            }
        }
        jgo(str,0,str.size()-1);
        for(i=0,j=1;j<str.size();++j){
            if(str[j]==' ') jgo(str,i,j-1),i=j+1,j+=1;
        }
        jgo(str,i,j-1);
        return str;
    }
};