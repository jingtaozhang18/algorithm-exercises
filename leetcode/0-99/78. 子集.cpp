// https://leetcode-cn.com/problems/subsets/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(vector<int>& nums, int i, vector<int>& path, vector<vector<int>>& ans){
        if(i==nums.size()) {
            ans.push_back(path);
            return;
        }
        jgo(nums, i+1, path, ans);
        path.push_back(nums[i]);
        jgo(nums, i+1, path, ans);
        path.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        jgo(nums, 0, path, ans);
        return ans;
    }
};