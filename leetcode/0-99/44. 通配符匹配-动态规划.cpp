// https://leetcode-cn.com/problems/wildcard-matching/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i, j;
        // 去除多余的*， 多想想，错了一千遍。不要判断没有确定的区域
        for(i=0,j=-1;i<p.size();++i){
            if(p[i]!='*') p[++j]=p[i];
            else {
                if(j>=0&&p[j]=='*') continue;
                else p[++j]=p[i];
            }
        }
        int m=s.size(), n=j+1;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n]=true;
        if(p[n-1]=='*') dp[m][n-1]=true;
        for(i=m-1;i>=0;--i){
            for(j=n-1;j>=0;--j) {
                if(p[j]!='*') dp[i][j]=dp[i+1][j+1]&(p[j]=='?'|p[j]==s[i]);
                else dp[i][j]=dp[i+1][j]|dp[i+1][j+1]|dp[i][j+1]; // 此处好好想
            }
        }
        // for(i=0;i<=m;++i){
        //     for(j=0;j<=n;++j) cout<<dp[i][j]<<" ";
        //     cout<<endl;
        // }
        return dp[0][0];
    }
};