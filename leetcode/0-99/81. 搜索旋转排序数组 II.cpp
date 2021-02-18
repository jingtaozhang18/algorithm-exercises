// https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left=0, size=nums.size(), right=size-1, mid, rt, mm;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]>nums[right]) left=mid+1;
            else {
                if(nums[mid]<nums[right]) right=mid;
                else --right;
            }
        }
        if(left==0&&nums[left]==nums[size-1]){ // 确定真正旋转位置
            left=size-1;
            while(left>0&&nums[left-1]==nums[left]) --left;
        }
        rt=left, left=0, right=size-1;
        while(left<=right){
            mid=left+(right-left)/2;
            mm=(rt+mid)%size;
            if(target==nums[mm]) return true;
            else if(nums[mm]<target) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
};