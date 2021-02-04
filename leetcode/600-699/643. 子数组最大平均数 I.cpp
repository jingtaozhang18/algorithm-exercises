// https://leetcode-cn.com/problems/maximum-average-subarray-i/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0, i=0, ans=INT_MIN;
        for(i=0;i<nums.size();++i){
            sum+=nums[i];
            if(i>=k-1){
                ans=max(ans, sum);
                sum-=nums[i-k+1];
            }
        }
        return (double)ans/k;
    }
};