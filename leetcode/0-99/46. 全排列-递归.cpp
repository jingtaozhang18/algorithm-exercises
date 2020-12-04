// https://leetcode-cn.com/problems/permutations/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(vector<int>&nums, vector<vector<int>>&ans, int index){
        int i,t;
        if(index==nums.size()) ans.push_back(nums);
        for(int i=index;i<nums.size();++i){
            t=nums[index], nums[index]=nums[i], nums[i]=t;
            jgo(nums, ans, index+1);
            t=nums[index], nums[index]=nums[i], nums[i]=t;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        jgo(nums, ans, 0);
        return ans;
    }
};