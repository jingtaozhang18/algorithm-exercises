// https://leetcode-cn.com/problems/two-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        int i,j;
        for(i=0;i<nums.size();++i){
            for(j=i+1;j<nums.size();++j){
                if(nums[i]+nums[j]==target) {
                    ans[0]=i,ans[1]=j;
                    return ans;
                }
            }
        }
        return ans;
    }
};