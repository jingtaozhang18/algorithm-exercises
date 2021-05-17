// https://leetcode-cn.com/problems/max-consecutive-ones/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int i, ans=0, t=0;
        for(i=0;i<nums.size();++i){
            if(nums[i]==1) t++;
            else t=0;
            ans=max(ans, t);
        }
        return ans;
    }
};