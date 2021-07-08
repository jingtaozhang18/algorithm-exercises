// https://leetcode-cn.com/problems/binary-subarrays-with-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> mp;
        mp[0]=1;
        int i, ans=0;
        for(i=0;i<nums.size();++i){
            if(i>0) nums[i]+=nums[i-1];
            auto p=mp.find(nums[i]-goal);
            if(p!=mp.end()) ans+=p->second;
            mp[nums[i]]++;
        }
        return ans;
    }
};
