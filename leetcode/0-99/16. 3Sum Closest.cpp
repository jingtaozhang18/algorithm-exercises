// https://leetcode-cn.com/problems/3sum-closest/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans=5*1e4;
        int i, j, k, x, n=nums.size(), left, right, mid;
        for(i=0;i<n-2;++i){
            for(j=i+1;j<n-1;++j){
                x=target-nums[i]-nums[j];
                left=j+1, right=n-1;
                while(left<=right){
                    mid=left+(right-left)/2;
                    if(nums[mid]<x) left=mid+1;
                    else right=mid-1;
                }
                if(left>=n) x=nums[i]+nums[j]+nums[n-1];
                else if(left==j+1) x=nums[i]+nums[j]+nums[left];
                else {
                    x=nums[i]+nums[j]+nums[left-1];
                    if(abs(x-target)<abs(ans-target)) ans=x;
                    x=nums[i]+nums[j]+nums[left];
                    if(abs(x-target)<abs(ans-target)) ans=x;
                }
                if(abs(x-target)<abs(ans-target)) ans=x;
            }
        }
        return ans;
    }
};