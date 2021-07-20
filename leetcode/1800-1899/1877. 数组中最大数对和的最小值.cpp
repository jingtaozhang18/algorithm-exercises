// https://leetcode-cn.com/problems/minimize-maximum-pair-sum-in-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i, m=nums.size(), ans=INT_MIN;
        for(i=0;i*2<m;++i) ans=max(nums[i]+nums[m-1-i], ans);
        return ans;
    }
};
