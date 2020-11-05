// https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if(!nums.size()) return ans;
        int i,j,x,t;
        for(i=k-1;i>0;i--) if(nums[i-1]<nums[i]) nums[i-1]=nums[i]; // 后面大覆盖前面
        
        for(i=0,j=k-1;j<nums.size();++i,++j){
            for(x=j;x>i;--x)
                if(nums[x]>nums[x-1]) // 大就像前覆盖
                    nums[x-1]=nums[x];
                else
                    break;
            ans.push_back(nums[i]);
        }
        return ans;
    }
};