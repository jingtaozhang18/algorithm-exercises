// https://leetcode-cn.com/problems/3sum-closest/
#include<bits/stdc++.h>
using namespace std;

// n^2*log(n)
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

// n^2
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i, j, k, ans=-1, best=5*1e4, n=nums.size(), x;
        for(i=0;i<n-2;){
            j=i+1, k=n-1;
            while(j<k){
                x=nums[i]+nums[j]+nums[k];
                if(abs(x-target)<best) best=abs(x-target), ans=x;
                if(best==0) return ans;
                else if(x<target){
                    do{++j;}while(j<k&&nums[j-1]==nums[j]);
                }else{
                    do{--k;}while(j<k&&nums[k+1]==nums[k]);
                }
            }
            do{++i;}while(i<n-2&&nums[i-1]==nums[i]);
        }
        return ans;
    }
};
