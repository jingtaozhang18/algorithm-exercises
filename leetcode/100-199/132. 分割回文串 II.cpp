// https://leetcode-cn.com/problems/palindrome-partitioning-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> mem;
    int jgo(vector<vector<bool>> &dp, int i, int n){
      if(i==n) return 0;
      if(mem.find(i)!=mem.end()) return mem[i];
      int ans=INT_MAX;
      for(int k=i;k<n;++k){
        if(dp[i][k]){
          ans=min(ans, jgo(dp, k+1, n)+1);
        }
      }
      return mem[i]=ans;
    }
    int minCut(string s) {
      int i, j, k, n = s.size();
      vector<vector<bool>> dp(n, vector<bool>(n, true));
      for(k=1;k<n;++k){
        for(i=0;i<n-k;++i){
          j=i+k;
          dp[i][j]=dp[i+1][j-1]&s[i]==s[j];
        }
      }
      return jgo(dp, 0, n)-1;
    }
};