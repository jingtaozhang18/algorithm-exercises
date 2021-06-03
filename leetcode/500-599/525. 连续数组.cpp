// https://leetcode-cn.com/problems/contiguous-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int acc=0, i, n=nums.size(), ans=0;
        unordered_map<int, int> mp;
        mp[0]=-1;
        for(i=0;i<n;++i){
            acc+=nums[i]==1?1:-1;
            if(mp.find(acc)!=mp.end()) ans=max(ans, i-mp[acc]);
            else mp[acc]=i;
        }
        return ans;
    }
};