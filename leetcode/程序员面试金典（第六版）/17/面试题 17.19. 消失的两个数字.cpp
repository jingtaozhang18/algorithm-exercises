// https://leetcode-cn.com/problems/missing-two-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        nums.push_back(-1);
        nums.push_back(-1);
        int i, size=nums.size();
        vector<int> ans;
        for(i=0;i<size-2;++i){
            while(nums[i]!=-1&&nums[i]!=i+1) swap(nums[i], nums[nums[i]-1]);
        }
        for(i=0;i<size;++i){
            if(nums[i]!=i+1) ans.push_back(i+1);
        }
        return ans;
    }
};