// https://leetcode-cn.com/problems/multiply-strings/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        string ans="0";
        int i, j, k, x, a, b, acc, m=num1.size(), n=num2.size(), size;
        for(i=m-1, k=1;i>=0;--i, ++k){
            acc=0, size=ans.size()-k;
            if(size<0) ans="0"+ans, size=0;
            for(j=n-1;j>=0;--j){
                x=acc+(num2[j]-'0')*(num1[i]-'0')+(ans[size]-'0');
                acc=x/10;
                x=x%10;
                ans[size--]=x+'0';
                if(size<0&&(j>0||acc)) ans="0"+ans, size=0;
            }
            while(acc){
                x = acc+ans[size]-'0';
                acc=x/10;
                x=x%10;
                ans[size--]=x+'0';
                if(size<0&&acc) ans="0"+ans, size=0;
            }
        }
        return ans;
    }
};