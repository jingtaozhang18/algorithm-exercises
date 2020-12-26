// https://leetcode-cn.com/problems/4sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i,j,left,right,lt,size=nums.size();
        for(i=0;i<size-3;){
            lt=target-nums[i];
            for(j=i+1;j<size-2;){
                lt=lt-nums[j];
                left=j+1, right=size-1;
                while(left<right){
                    if(nums[left]+nums[right]==lt){
                        // 匹配到了
                        ans.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        do{++left;}while(left<right&&nums[left-1]==nums[left]);
                        do{--right;}while(left<right&&nums[right+1]==nums[right]);
                    }else if(nums[left]+nums[right]<lt){
                        do{++left;}while(left<right&&nums[left-1]==nums[left]);
                    }else{
                        do{--right;}while(left<right&&nums[right+1]==nums[right]);
                    }
                }
                lt=lt+nums[j];
                do{++j;}while(j<size&&nums[j-1]==nums[j]);
            }
            do{++i;}while(i<size&&nums[i-1]==nums[i]);
        }
        return ans;
    }
};