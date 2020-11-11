// https://leetcode-cn.com/problems/next-permutation/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j,k,m,n;
        for(i=nums.size()-1;i>0;--i){
            if(nums[i-1]<nums[i]){
                for(j=i;j<nums.size()&&nums[j]>nums[i-1];++j); // 定位到最后一个比i-1大的位置
                for(--j;j>=i;--j) k=nums[j],nums[j]=nums[j-1],nums[j-1]=k; // 逐个位置移到i-1
                for(m=i+1,n=nums.size()-1;m<n;++m,--n) k=nums[m],nums[m]=nums[n],nums[n]=k;
                for(j=i;j<nums.size()-1&&nums[j]>nums[j+1];++j) k=nums[j],nums[j]=nums[j+1],nums[j+1]=k;
                return;
            }
        }
        for(i=0,j=nums.size()-1;i<j;i++,j--) k=nums[i],nums[i]=nums[j],nums[j]=k;
    }
};