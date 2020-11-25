// https://leetcode-cn.com/problems/UlBDOe/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(string leaves) {
        int i, n=leaves.size();
        vector<vector<int>>dp(n, vector<int>(3,INT_MAX));
        dp[0][0]=leaves[0]!='r'; // 错误点： 需要等待一段时间才能进入status 1
        for(i=1;i<n;++i){
            dp[i][0]=dp[i-1][0]+(leaves[i]=='r'?0:1);
            dp[i][1]=min(dp[i-1][0], dp[i-1][1])+(leaves[i]=='y'?0:1);
            if(i>1)dp[i][2]=min(dp[i-1][1], dp[i-1][2])+(leaves[i]=='r'?0:1); // 错误点： 需要等待一段时间才能进入status 2
        }
        return dp[n-1][2];
    }
};