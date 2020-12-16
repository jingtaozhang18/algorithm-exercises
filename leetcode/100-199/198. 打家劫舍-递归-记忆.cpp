// https://leetcode-cn.com/problems/house-robber/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> mem;
    int jgo(vector<int>& nums, int index){
        if(index>=nums.size()) return 0;
        auto p=mem.find(index);
        if(p!=mem.end()) return p->second;
        int ans=max(nums[index]+jgo(nums, index+2), jgo(nums, index+1));
        mem[index]=ans;
        return ans;
    }
    int rob(vector<int>& nums) {
        mem.clear();
        return jgo(nums, 0);
    }
};