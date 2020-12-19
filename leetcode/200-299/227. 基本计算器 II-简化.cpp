// https://leetcode-cn.com/problems/basic-calculator-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isdigit(char c){return c>='0'&&c<='9';}
    int calculate(string s) {
        char sign='+'; int num=0, a;
        stack<int> sta;
        int index=0;
        for(char c:s){
            if(isdigit(c)) num=num*10+(c-'0');
            if((!isdigit(c)&&c!=' ')||index==s.size()-1) {
                if(sign=='+') sta.push(num);
                else if(sign=='-') sta.push(-num);
                else if(sign=='*'||sign=='/'){
                    a=sta.top(); sta.pop();
                    if(sign=='*') sta.push(a*num);
                    else sta.push(a/num);
                }
                sign=c, num=0;
            }
            ++index;
        }
        num=0;
        do{
            num+=sta.top();
            sta.pop();
        }while(!sta.empty());
        return num;
    }
};