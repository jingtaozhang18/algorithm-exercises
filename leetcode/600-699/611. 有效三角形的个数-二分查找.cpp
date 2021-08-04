// https://leetcode-cn.com/problems/valid-triangle-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jfind(vector<int>&arr, int left, int right, int target){
        int center;
        while(left<=right){
            center=(left+right)/2;
            if(arr[center]>=target) right=center-1;
            else left=center+1;
        }
        return right;
    }
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0, j, m=nums.size(), k, ans=0;
        while(i<m&&nums[i]==0) ++i; // 定位到第一个非0的位置
        for(;i<m-2;++i){
            for(j=i+1;j<m-1;++j){
                k=jfind(nums, j+1, m-1, nums[i]+nums[j]);
                ans+=(k-j);
            }
        }
        return ans;
    }
};
