// https://leetcode-cn.com/problems/3sum/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(), nums.end());
        int i,l,r,size=nums.size(),a;
        for(i=0;i<size;++i){
            if(i!=0&&nums[i]==nums[i-1]) continue; // 去掉重复元素
            for(l=i+1,r=size-1;l<r;){
                a=nums[i]+nums[l]+nums[r];
                if(a==0) {
                    vector<int> t(3, 0);
                    t[0]=nums[i], t[1]=nums[l], t[2]=nums[r];
                    ans.push_back(t);
                    for(++l;l<r&&nums[l]==nums[l-1];++l);
                    for(--r;l<r&&nums[r]==nums[r+1];--r);
                }else if(a>0) for(--r;l<r&&nums[r]==nums[r+1];--r);
                else if(a<0) for(++l;l<r&&nums[l]==nums[l-1];++l);
            }
        }
        return ans;
    }
};