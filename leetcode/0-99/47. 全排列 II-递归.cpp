// https://leetcode-cn.com/problems/permutations-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(vector<int>& path, int index, vector<vector<int>>& ans){
        if(index==path.size()) ans.push_back(path);
        set<int> hs;
        int i;
        for(i=index;i<path.size();++i){
            if(hs.find(path[i])!=hs.end()) continue;
            swap(path[i], path[index]);
            jgo(path, index+1, ans);
            hs.insert(path[index]);
            swap(path[i], path[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        jgo(nums, 0, ans);
        return ans;
    }
};