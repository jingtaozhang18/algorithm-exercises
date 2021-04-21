// https://leetcode-cn.com/problems/decode-ways/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int i, n=s.size();
        if(n==0||s[i]=='0') return 0;
        int dp[n+1];
        for(i=0;i<=n;++i) dp[i]=0;
        dp[0]=1;
        for(i=0;i<n;++i){
            if('0'<s[i]) dp[i+1]=dp[i];
            if(i){
                if(s[i-1]!='0'){
                    int acc=s[i-1]-'0';
                    acc *= 10;
                    acc += s[i]-'0';
                    if(acc<=26)
                        dp[i+1]+=dp[i-1];
                }
            }
        }
        return dp[n];
    }
};