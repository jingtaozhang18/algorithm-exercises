// https://leetcode-cn.com/problems/strange-printer/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        int i, j, k, d, x, n=s.size();
        int dp[n][n];
        for(i=0;i<n;++i) for(j=0;j<n;++j) dp[i][j]=0;
        for(d=0;d<n;++d){
            for(i=0;i<n-d;++i){
                j=i+d;
                if(d==0) dp[i][j]=1;
                else{
                    if(s[i]==s[j]) dp[i][j]=dp[i][j-1];
                    else{
                        dp[i][j]=1000;
                        for(k=i;k<j;++k) 
                            dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]);
                    }
                }
 
            }
        }
        return dp[0][n-1];
    }
};