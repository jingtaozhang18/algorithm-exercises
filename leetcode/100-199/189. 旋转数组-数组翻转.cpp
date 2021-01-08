// https://leetcode-cn.com/problems/rotate-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(vector<int>& nums, int left, int right){
        while(left<right) swap(nums[left++], nums[right--]);
    }
    void rotate(vector<int>& nums, int k) {
        int size=nums.size();
        k%=size;
        if(k==0) return;
        jgo(nums, 0, size-1-k);
        jgo(nums, size-k, size-1);
        jgo(nums, 0, size-1);
    }
};