// https://leetcode-cn.com/problems/product-of-array-except-self/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int m=nums.size(), i, acc;
        vector<int> ans(m);
        ans[0]=1;
        for(i=0;i<m-1;++i) ans[i+1]=ans[i]*nums[i];
        for(acc=1,i=m-1;i>0;--i) acc*=nums[i], ans[i-1]=ans[i-1]*acc;
        return ans;
    }
};