// https://leetcode-cn.com/contest/weekly-contest-233/problems/maximum-ascending-subarray-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int i, ans=nums[0], acc=nums[0];
        for(i=1;i<nums.size();++i){
            if(nums[i]>nums[i-1]) acc+=nums[i];
            else acc=nums[i];
            ans=max(ans, acc);
        }
        return ans;
    }
};