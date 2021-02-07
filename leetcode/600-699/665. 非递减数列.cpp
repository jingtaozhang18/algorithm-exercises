// https://leetcode-cn.com/problems/non-decreasing-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        // 最长非递减子序列
        vector<int> dp;
        int left, right, mid, i, size=nums.size(), p;
        for(i=0;i<size;++i){
            p=nums[i];
            left=0, right=dp.size()-1;
            while(left<=right){
                mid=left+(right-left)/2;
                if(dp[mid]<=p) left=mid+1; // 相等可以向后延续
                else right=mid-1;
            }
            if(left==dp.size()) dp.push_back(p);
            else dp[left]=min(dp[left], p);
        }
        return size-dp.size()<=1;
    }
};