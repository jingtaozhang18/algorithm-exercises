// https://leetcode-cn.com/problems/basic-calculator-ii/
// 在基本计算器的基础上进行了改进，在题目的要求之上支持括号的使用
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int readnum(string &s, int &i, int &len){
        int num=0;
        while(s[i]>='0' && s[i]<='9' && i<len)
            num*=10, num+=s[i]-'0', i++;
        --i;
        return num;
    };
    int doc(char& op, int a, int b){
        // cout<<a<<op<<b<<endl;
        if(op=='+') return a+b;
        else if(op=='-') return b-a;
        else if(op=='*') return a*b;
        else if(op=='/') return b/a;
        else return 0;
    };
    int calc(string &s, int& i, int &len){
        map<char, int> mp;
        mp['+']=0,mp['-']=0,mp['*']=1,mp['/']=1;
        int ans=0, a, b;
        char p;
        stack<char> op;
        stack<int> num;
        for(;i<len;++i){
            if(s[i]>='0' && s[i]<='9') num.push(readnum(s,i,len));
            else if(s[i]=='(') num.push(calc(s,++i,len));
            else if(s[i]==')') {
                while(!op.empty()){
                    a=num.top(); num.pop();
                    b=num.top(); num.pop();
                    p=op.top(); op.pop();
                    num.push(doc(p,a,b));
                }
            }
            else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
                while(!op.empty() && mp[s[i]]<=mp[op.top()]){ // 向前计算
                    a=num.top(); num.pop();
                    b=num.top(); num.pop();
                    p=op.top(); op.pop();
                    num.push(doc(p,a,b));
                }
                op.push(s[i]);
            }
        }
        while(!op.empty()){
            a=num.top(); num.pop();
            b=num.top(); num.pop();
            p=op.top(); op.pop();
            num.push(doc(p,a,b));
        }
        return num.top();
    }
    int calculate(string s) {
        int i=0,len=s.size();
        return calc(s,i,len);
    }
};