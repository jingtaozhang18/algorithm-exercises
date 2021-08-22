// https://leetcode-cn.com/problems/bu-ke-pai-zhong-de-shun-zi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n0=0,i,j;
        for(i=0;i<nums.size()&&nums[i]==0;++i) n0++;
        if(i<nums.size()) j=nums[i]; // 希望遇到的值
        for(i+=1,j+=1;i<nums.size();++j){
            // cout<<nums[i]<<" "<<j<<" "<<n0<<endl;
            if((nums[i]!=j&&!n0--)) return false;
            if(nums[i]==j) i++; // 匹配才向后
        }
        return true;
    }
};