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

// 先定位到
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size(), left=0, right=n-1, mid, pivot=0, i;
        // 先找到数组的最小值
        while(left<=right){
            if(nums[left]<nums[right]) {
                pivot=left;
                break;
            }
            mid=left+(right-left)/2;
            if(nums[left]<nums[mid]){
                left=mid+1;
            }else if(nums[left]>nums[mid]){
                right=mid;
            }else{
                for(i=left+1;i<=right;++i) if(nums[i-1]>nums[i]) break;
                pivot=(i==right+1)?left:i; // 错误点，判断最开始的位置
                break;
            }
        }
        if(pivot==0&&nums[pivot]==nums[n-1]) pivot=n-1;
        while(pivot>0&&nums[pivot-1]==nums[pivot]) --pivot; // 错误点：纠正最开始的位置
        left=0, right=n-1;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[(mid+pivot)%n]==target) return true;
            else if(nums[(mid+pivot)%n]<target) left=mid+1;
            else right=mid-1;
        }
        return false;
    }
};