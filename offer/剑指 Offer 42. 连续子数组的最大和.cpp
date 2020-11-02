// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0], i;
        for(i=1;i<nums.size();++i){
            nums[i]=max(nums[i], nums[i]+nums[i-1]); // 拼接或者不拼接
            ans=max(ans, nums[i]);
        }
        return ans;
    }
};