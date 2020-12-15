// https://leetcode-cn.com/problems/target-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> mp;
    // 使用动态规划的思想消除重叠子问题，状态的定义从递归函数中发现
    int jgo(vector<int>& nums, int index, long long rest){
        if(index==nums.size()&&rest==0) return 1;
        if(index==nums.size()) return 0;
        string key=to_string(index)+"_"+to_string(rest);
        if(mp.find(key)!=mp.end()) return mp[key];
        int ans=0;
        rest-=nums[index];
        ans+=jgo(nums, index+1, rest);
        rest+=nums[index], rest+=nums[index]; // 错误点 题目没有保证S的范围
        ans+=jgo(nums, index+1, rest);
        mp[key]=ans;
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        return jgo(nums, 0, S);
    }
};