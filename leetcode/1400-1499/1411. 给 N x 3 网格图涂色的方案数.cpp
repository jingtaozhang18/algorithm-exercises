// https://leetcode-cn.com/problems/number-of-ways-to-paint-n-3-grid/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
      vector<vector<long long>> dp(n, vector<long long>(2, 6));
      // dp[i][0] 第i+1层的ABA类型的数量
      // dp[i][1] 第i+1层的ABC类型的数量
      int i, mod=1e9+7;
      for(i=1;i<n;++i){
        dp[i][0]=(dp[i-1][0]*3+dp[i-1][1]*2)%mod;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1])*2%mod;
      }
      return (dp[n-1][0]+dp[n-1][1])%mod;
    }
};