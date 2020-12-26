// https://leetcode-cn.com/problems/jump-game-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int ans=0, i=0, now_max=0, t=0, size=nums.size();
        while(now_max<size-1){
            for(;i<=now_max;++i) t=max(t, i+nums[i]);
            ans++, now_max=t;
        }
        return ans;
    }
};