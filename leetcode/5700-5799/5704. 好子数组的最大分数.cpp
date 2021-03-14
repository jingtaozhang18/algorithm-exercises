// https://leetcode-cn.com/contest/weekly-contest-232/problems/maximum-score-of-a-good-subarray/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i, j, n=nums.size(), left=k, right=k, diff;
        int mv=nums[k], p=nums[k];
        while(left>=0||right<n){
            if(left==0) ++right;
            else if(right==n-1) --left;
            else{
                if(nums[left-1]>nums[right+1]) --left;
                else ++right;
            }
            if(left<0||right>=n) break;
            p=min(p, min(nums[left], nums[right]));
            while(left>=0&&nums[left]>=p) --left;
            while(right<n&&nums[right]>=p) ++right;
            ++left, --right;
            // cout<<left<<" "<<right<<" "<<p<<endl;
            mv=max(mv, p*(right-left+1));
        }
        
        return mv;
    }
};