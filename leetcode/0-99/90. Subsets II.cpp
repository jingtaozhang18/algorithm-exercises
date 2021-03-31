// https://leetcode-cn.com/problems/subsets-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(vector<int>& nums, int i, vector<int>&path, vector<vector<int>>&ans){
        if(i==nums.size()) {
            ans.push_back(path); 
            return; // 错误点，没有及时退出递归
        }
        int j, k=0;
        for(j=i+1;j<nums.size()&&nums[j]==nums[i];++j);
        jgo(nums, j, path, ans);
        for(;i<j;++i){
            path.push_back(nums[i]);
            ++k;
            jgo(nums, j, path, ans);
        }
        while(k--) path.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        jgo(nums, 0, path, ans);
        return ans;
    }
};