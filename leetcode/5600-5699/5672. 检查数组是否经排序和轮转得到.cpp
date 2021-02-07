// https://leetcode-cn.com/problems/check-if-array-is-sorted-and-rotated/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int ans=0, i, size=nums.size();
        for(i=1;i<size;++i){
            if(nums[i]<nums[i-1]) ans++;
        }
        if(ans==0) return true;
        if(ans==1) return nums[size-1]<=nums[0];
        return false;
    }
};