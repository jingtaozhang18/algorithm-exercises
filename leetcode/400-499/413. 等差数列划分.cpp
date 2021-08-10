// https://leetcode-cn.com/problems/arithmetic-slices/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int i, acc=1, diff=nums[1]-nums[0], ans=0;
        for(i=2;i<nums.size();++i){
            if(nums[i]-nums[i-1]==diff){
                acc++;
                ans+=acc-1;
            }else{
                diff=nums[i]-nums[i-1];
                acc=1;
            }
        }
        return ans;
    }
};
