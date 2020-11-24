// https://leetcode-cn.com/problems/uncrossed-lines/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m=A.size(), n=B.size(),i,j,ans=0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(A[i]==B[j]) dp[i][j]=((i>0&&j>0)?dp[i-1][j-1]:0)+1;
                else dp[i][j]=max(i>0?dp[i-1][j]:0, j>0?dp[i][j-1]:0);
                ans=max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};