// https://leetcode-cn.com/problems/target-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 回溯，穷举
    int jgo(vector<int>& nums, int index, int rest){
        if(index==nums.size()&&rest==0) return 1;
        if(index==nums.size()) return 0;
        int ans=0;
        rest-=nums[index];
        ans+=jgo(nums, index+1, rest);
        rest+=nums[index], rest+=nums[index];
        ans+=jgo(nums, index+1, rest);
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return jgo(nums, 0, S);
    }
};