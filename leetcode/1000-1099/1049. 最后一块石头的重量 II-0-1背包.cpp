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