// https://leetcode-cn.com/problems/calculator-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jread(string &s, int &i){
        int ans=0;
        while(i<s.size()&&s[i]>='0'&&s[i]<='9') ans*=10, ans+=s[i]-'0', ++i;
        --i;
        return ans;
    }
    int calculate(string s) {
        stack<int> sta;
        int i, m=s.size(), x, y, acc=0;
        char op='+';
        for(i=0;i<m;++i){
            if(s[i]==' ') continue;
            else if(s[i]=='+') op='+';
            else if(s[i]=='-') op='-';
            else if(s[i]=='*') op='*';
            else if(s[i]=='/') op='/';
            else{
                x=jread(s, i);
                if(op=='+') sta.push(x);
                else if(op=='-') sta.push(-x);
                else if(op=='*') {
                    y=sta.top(); sta.pop();
                    sta.push(y*x);
                }else if(op=='/') {
                    y=sta.top(); sta.pop();
                    sta.push(y/x);
                }
            }
        }
        while(sta.size()){
            y=sta.top(); sta.pop();
            acc+=y;
        }
        return acc;
    }
};
