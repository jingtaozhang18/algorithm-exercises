// https://leetcode-cn.com/problems/increasing-subsequences/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* next[220];
    node(int val):val(val){memset(next, 0, sizeof next);}
};
class Solution {
public:
    void jgo(node* root, vector<vector<int>>& ans, vector<int>& path, int deep){
        for(auto nd:root->next){
            if(!nd) continue;
            path.push_back(nd->val);
            if(deep) ans.push_back(path);
            jgo(nd, ans, path, deep+1);
            path.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        node *root=new node(INT_MIN);
        int i, j, t;
        // 构建
        vector<node*> arr;
        arr.push_back(root);
        for(j=0;j<nums.size();++j){
            t=arr.size();
            for(i=0;i<t;++i){
                if(nums[j]>=arr[i]->val&&!arr[i]->next[nums[j]+100]){
                    arr[i]->next[nums[j]+100]=new node(nums[j]);
                    arr.push_back(arr[i]->next[nums[j]+100]);
                }
            }
        }
        vector<vector<int>> ans;
        vector<int> path;
        jgo(root, ans, path, 0);
        return ans;
    }
};