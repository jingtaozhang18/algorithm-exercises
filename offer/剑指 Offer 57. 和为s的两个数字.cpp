// https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        int i,j,s;
        for(i=0,j=nums.size()-1;i<j;){
            s=nums[i]+nums[j];
            if(s==target) {
                ans[0]=nums[i],ans[1]=nums[j];
                return ans;
            }else if(s<target) ++i;
            else --j;
        }
        return ans;
    }
};