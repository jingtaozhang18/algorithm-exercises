// https://leetcode-cn.com/problems/partition-equal-subset-sum/
#include<bits/stdc++.h>
using namespace std;

// 两个数组轮番迭代
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int acc=0, n=nums.size(), i, j;
        for(auto e:nums) acc+=e;
        if(acc%2) return false;
        acc>>=1;
        vector<bool> dp(acc+1, false);
        dp[0]=true;
        for(i=0;i<n;++i){
            vector<bool> tdp(dp);
            for(j=0;j<=acc;++j){
                if(dp[j]&&j+nums[i]<=acc){
                    tdp[j+nums[i]]=true;
                }
            }
            dp = move(tdp);
        }
        return dp[acc];
    }
};

// 使用一个数组，每次修改的内容保证下次不再需要的顺序进行修改
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int acc=0, n=nums.size(), i, j;
        for(auto e:nums) acc+=e;
        if(acc%2) return false;
        acc>>=1;
        vector<bool> dp(acc+1, false);
        dp[0]=true;
        for(i=0;i<n;++i){
            for(j=acc;j>=0&&j-nums[i]>=0;--j){
                if(dp[j-nums[i]]){
                    dp[j]=true;
                }
            }
        }
        return dp[acc];
    }
};