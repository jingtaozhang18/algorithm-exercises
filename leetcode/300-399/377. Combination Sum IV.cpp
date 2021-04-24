// https://leetcode-cn.com/problems/combination-sum-iv/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int i;
        int dp[target+1]; dp[0]=1;
        sort(nums.begin(), nums.end());
        for(i=1;i<=target;++i){
            dp[i]=0;
            for(auto &e:nums){
                if(i-e>=0&&dp[i-e]<INT_MAX-dp[i]) dp[i]+=dp[i-e]; // dp[i-e]<INT_MAX-dp[i]严卡题意，太过厉害的判断条件
                else break;
            }
        }
        return dp[target];
    }
};