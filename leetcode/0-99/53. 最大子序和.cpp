// https://leetcode-cn.com/problems/maximum-subarray/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        for(int i=0;i<nums.size();++i){
            if(i&&nums[i-1]>0) nums[i]+=nums[i-1];
            ans=max(ans, nums[i]);
        }
        return ans;
    }
};