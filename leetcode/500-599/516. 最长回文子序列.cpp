// https://leetcode-cn.com/problems/longest-palindromic-subsequence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size=s.size(), i, j, diff;
        vector<vector<int>>dp(size, vector<int>(size, 0));
        for(diff=0;diff<size;++diff){
            for(i=0;i<size-diff;++i){
                j=i+diff;
                if(diff==0) dp[i][j]=1;
                else if(diff==1) dp[i][j]=s[i]==s[j]?2:1;
                else{
                    if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
                    dp[i][j]=max({dp[i+1][j], dp[i][j], dp[i][j-1]});
                }
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return dp[0][size-1];
    }
};