// https://leetcode-cn.com/problems/jump-game/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i, n=nums.size(), max_p=0;
        for(i=0;i<n&&max_p>=i;++i) max_p=max(max_p, nums[i]+i);
        return max_p>=n-1;
    }
};