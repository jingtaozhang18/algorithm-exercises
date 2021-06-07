// https://leetcode-cn.com/problems/combination-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(vector<int>& candidates, int index, int target, vector<vector<int>>& ans, vector<int>& path){
        if(target==0) {ans.push_back(path); return;}
        if(index==candidates.size()) return;
        jgo(candidates, index+1, target, ans, path);
        int acc=0;
        while(target>=candidates[index]){
            path.push_back(candidates[index]); acc++;
            target-=candidates[index];
            jgo(candidates, index+1, target, ans, path);
        }
        while(acc--) path.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        jgo(candidates, 0, target, ans, path);
        return ans;
    }
};