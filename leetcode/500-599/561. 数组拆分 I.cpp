// https://leetcode-cn.com/problems/array-partition-i/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ans=0, i;
        sort(nums.begin(), nums.end());
        for(i=0;i<nums.size();i+=2){
            // ans+=min(nums[i], nums[i+1]);
            ans+=nums[i]; // 已经排序了，大哥
        }
        return ans;
    }
};