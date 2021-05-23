// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left=0, right=nums.size()-1, mid, i, j, a=-1, b=-1;
        while(left<=right){
            mid=(left+right)>>1;
            if(nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        if(left<nums.size()&&nums[left]==target) a=left;
        left=0, right=nums.size()-1;
        while(left<=right){
            mid=(left+right)>>1;
            if(nums[mid]<=target) left=mid+1;
            else right=mid-1;
        }
        if(right>=0&&nums[right]==target)b=right;
        return vector<int>{a, b};
    }
};