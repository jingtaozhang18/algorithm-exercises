// https://leetcode-cn.com/problems/basic-calculator-iii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isdigit(char c){ return c>='0'&&c<='9'; }
    int jgo(string&s, int& index){
        long long num=0, pre; // 错误点: num在最小负数的时候会溢出
        char op='+', c;
        stack<int> sta;
        for(;index<s.size();++index){
            c=s[index];
            if(c=='(') {num=jgo(s, ++index);}
            else if(isdigit(c)) num=num*10+(c-'0');
            c=s[index];
            if((!isdigit(c)&&c!=' ')||index>=s.size()-1){
                if(op=='+') sta.push(num);
                else if(op=='-') sta.push(-num);
                else if(op=='*'){
                    pre=sta.top();
                    sta.pop();
                    sta.push(pre*num);
                }else{
                    pre=sta.top();
                    sta.pop();
                    sta.push(pre/num);
                }
                if(c==')') {++index; break;}
                op=c, num=0;
            }
        }
        num=0;
        while(!sta.empty()){
            num+=sta.top();
            sta.pop();
        }
        cout<<num<<endl;
        return num;
    }
    int calculate(string s) {
        int index=0;
        return jgo(s, index);
    }
};