// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums, int left, int right) { // [left, right]
        int mid;
        if(left==right||nums[left]<nums[right]) return nums[left];
        mid=left+(right-left)/2;
        return min(findMin(nums, left, mid), findMin(nums, mid+1, right));
    }
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size()-1);
    }
};

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1, mid;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]>nums[right]) left=mid+1;
            else {
                if(nums[mid]<nums[right]) right=mid;
                else --right;
            }
        }
        return nums[left];
    }
};