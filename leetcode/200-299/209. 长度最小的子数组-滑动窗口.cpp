// https://leetcode-cn.com/problems/minimum-size-subarray-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0, right=0, acc=0, size=nums.size(), ans=INT_MAX;
        while(right<size){
            acc+=nums[right++];
            while(acc-nums[left]>=target) acc-=nums[left++];
            if(acc>=target) ans=min(ans, right-left);
        }
        return ans==INT_MAX?0:ans;
    }
};