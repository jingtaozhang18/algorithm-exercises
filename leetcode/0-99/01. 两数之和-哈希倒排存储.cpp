// https://leetcode-cn.com/problems/two-sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        map<int, int> mp;
        int i, k;
        map<int, int>::iterator p;
        for(i=0;i<nums.size();++i){
            k=target-nums[i];
            if((p=mp.find(k))!=mp.end()){
                ans[0]=p->second;
                ans[1]=i;
                return ans;
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};