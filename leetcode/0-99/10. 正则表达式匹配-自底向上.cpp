// https://leetcode-cn.com/problems/regular-expression-matching/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i,j,ls=s.size(),lp=p.size(),a,b;
        vector<vector<bool>> dp(ls+1, vector<bool>(lp+1, false));
        // 初始化边界
        dp[ls][lp]=true;
        for(j=lp-1;j>0;j-=2){
            if(p[j]=='*') dp[ls][j]=dp[ls][j-1]=true;
            else break;
        }
        for(j=lp-1;j>=0;--j){
            for(i=ls-1;i>=0;--i){
                if(p[j]!='*') dp[i][j]=dp[i][j]|((p[j]=='.'||s[i]==p[j])&dp[i+1][j+1]);
                else{
                    dp[i][j]=dp[i][j]|dp[i][j+1]; // 匹配0个元素
                    if(p[j-1]=='.'||s[i]==p[j-1]) dp[i][j]=dp[i][j]|dp[i+1][j]; // 错误点， 匹配多个元素的时候应该看[i+1][j] 而不是[i+1][j+1]
                    dp[i][j-1]=dp[i][j];
                }
            }
            // for(a=0;a<ls;++a){
            //     for(b=0;b<lp;++b){
            //         cout<<dp[a][b]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl<<endl;
            if(p[j]=='*') --j;
        }
        return dp[0][0];
    }
};