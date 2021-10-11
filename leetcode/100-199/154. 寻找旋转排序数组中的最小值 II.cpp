// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums, int left, int right) { // [left, right]
        int mid;
        if (left == right || nums[left] < nums[right]) return nums[left];
        mid = left + (right - left) / 2;
        return min(findMin(nums, left, mid), findMin(nums, mid + 1, right));
    }
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
};

class Solution_fx_1 {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while (left < right) {
            mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) left = mid + 1;
            else {
                if (nums[mid] < nums[right]) right = mid;
                else --right;
            }
        }
        return nums[left];
    }
};

// 复习， 从左边考虑
class Solution_fx_2 {
public:
    int findMin(vector<int>& nums) {
        int left = 0, n = nums.size(), right = n - 1, mid, k;
        while (left <= right) {
            if (nums[left] < nums[right]) return nums[left];
            mid = left + (right - left) / 2;
            if (nums[left] < nums[mid]) left = mid + 1;
            else if (nums[left] > nums[mid]) right = mid;
            else {
                for (k = left + 1;k <= right;++k) if (nums[k - 1] > nums[k]) break;
                return (k == right + 1) ? nums[left] : nums[k];
            }
        }
        return -1;
    }
};