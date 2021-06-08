// https://leetcode-cn.com/problems/last-stone-weight-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        // 分成重量尽可能相等的两部分
        int n=stones.size(), i ,j, sum=0;
        for(auto e:stones) sum+=e;
        int acc = sum>>1;
        vector<int> dp(acc+1, false);
        dp[0]=true;
        for(i=0;i<n;++i){
            for(j=acc;j>=0&&j-stones[i]>=0;--j){
                if(dp[j-stones[i]]){
                    dp[j]=true;
                }
            }
        }
        for(j=acc;j>=0&&dp[j]==false;--j);
        return sum-2*j;
    }
};

// 复习。背包问题，代价和价值相等
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int acc, sum=0, i, j, n=stones.size();
        for(auto &e:stones) sum+=e;
        acc=sum>>1;
        int dp[n+1][acc+1];
        for(j=0;j<=acc;++j) dp[0][j]=0;
        for(i=1;i<=n;++i){
            for(j=0;j<=acc;++j){
                if(j-stones[i-1]>=0) dp[i][j]=stones[i-1]+dp[i-1][j-stones[i-1]];
                else dp[i][j]=0;
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }
        return sum-dp[n][acc]*2;
    }
};