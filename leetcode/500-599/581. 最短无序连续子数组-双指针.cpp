// https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int m=nums.size(), left=0, right=m-1, i;
        while(left+1<m&&nums[left]<=nums[left+1]) ++left;
        while(right-1>=0&&nums[right-1]<=nums[right]) --right;
        for(i=left+1;i<m;++i){
            while(left>=0&&nums[left]>nums[i]) --left;
        }
        for(i=right-1;i>=0;--i){
            while(right<m&&nums[i]>nums[right]) ++right;
        }
        return max(0, right-left-1);
    }
};
