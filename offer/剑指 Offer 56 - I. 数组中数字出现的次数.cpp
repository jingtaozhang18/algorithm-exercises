// https://leetcode-cn.com/problems/shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof/submissions/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int i, acc=0, a=0, b=0, j=1;
        for(i=0;i<nums.size();++i) acc^=nums[i];
        while((j&acc)==0) j<<=1;
        for(i=0;i<nums.size();++i) if(j&nums[i])a^=nums[i]; else b^=nums[i];
        vector<int> ans(2, a);
        ans[1]=b;
        return ans;
    }
};