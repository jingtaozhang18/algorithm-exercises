// https://leetcode-cn.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int left=0, right=0, size=nums.size(), ans=0, x;
        deque<int> dmax, dmin;
        while(right<size){
            x=nums[right++];
            while(dmax.size()&&dmax.back()<x) dmax.pop_back();
            while(dmin.size()&&dmin.back()>x) dmin.pop_back();
            dmax.push_back(x), dmin.push_back(x);
            while(left<right&&dmax.front()-dmin.front()>limit){
                x=nums[left++];
                if(x==dmax.front()) dmax.pop_front();
                if(x==dmin.front()) dmin.pop_front();
            }
            ans=max(ans,right-left);
        }
        return ans;
    }
};