// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size=nums.size(), left=0, right=size-1, mid, rt;
        while(left<right){
            mid=left+(right-left)/2;
            if(nums[mid]>nums[right]) left=mid+1;
            else right=mid;
        }
        rt=left, left=0, right=size-1; // rt: 先找到最小值的位置
        int mm;
        while(left<=right){
            mid=left+(right-left)/2;
            mm=(mid+rt)%size; // 映射到以最小值位置为0开始编号
            if(target==nums[mm]) return mm;
            else if(nums[mm]<target) left=mid+1;
            else right=mid-1;
        }
        return -1;
    }
};