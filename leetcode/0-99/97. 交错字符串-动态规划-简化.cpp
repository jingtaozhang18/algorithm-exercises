// https://leetcode-cn.com/problems/interleaving-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        vector<vector<bool>> dp(s1.size()+1, vector<bool>(s2.size()+1, false));
        int i,j;
        // dp[i][j] 表示s1[0, i-1]和s2[0, j-1]和s3[0, i+j-1]是交错字符串
        dp[0][0]=true;
        for(i=0;i<=s1.size();++i){
            for(j=0;j<=s2.size();++j){
                if(i>0) dp[i][j] = (s1[i-1]==s3[i+j-1]&&dp[i-1][j]);
                if(j>0) dp[i][j] = dp[i][j] || (s2[j-1]==s3[i+j-1]&&dp[i][j-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};