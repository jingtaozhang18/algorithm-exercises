// https://leetcode-cn.com/problems/string-to-integer-atoi/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(int&ans, int t){
        int a=INT_MAX/10, b=INT_MAX-a*10, c=INT_MIN/10, d=INT_MIN-c*10;
        if(ans>a)return 1;
        else if(ans==a&&t>b) return 1;
        else if(ans<c) return -1;
        else if(ans==c&&t<d) return -1;
        ans*=10, ans+=t;
        return 0;
    }
    int myAtoi(string s) {
        int i, t, ans=0, flag=1, sign=true;
        char ch;
        for(i=0;i<s.size();++i){
            ch=s[i];
            if(flag==1){
                if(ch==' ');
                else if(ch=='+'||ch=='-') flag=2, sign=ch=='+';
                else if(ch>='0'&&ch<='9'){
                    t=ch-'0';
                    t=jgo(ans, sign?t:-t);
                    if(t==1) return INT_MAX;
                    if(t==-1) return INT_MIN;
                    flag=3;
                }
                else break;
            }else if(flag==2){
                if(ch>='0'&&ch<='9'){
                    t=ch-'0';
                    t=jgo(ans, sign?t:-t);
                    if(t==1) return INT_MAX;
                    if(t==-1) return INT_MIN;
                    flag=3;
                }else break;
            }else if(flag==3){
                if(ch>='0'&&ch<='9'){
                    t=ch-'0';
                    t=jgo(ans, sign?t:-t);
                    if(t==1)return INT_MAX;
                    if(t==-1)return INT_MIN;
                }else break;
            }else break;
        }
        return ans;
    }

};