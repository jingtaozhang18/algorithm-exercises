// https://leetcode-cn.com/problems/next-permutation/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j,k,t;
        for(i=nums.size()-1;i>0;--i){
            if(nums[i-1]<nums[i]){ // 找到第一个逆序对
                j=i-1; // j小数
                for(k=nums.size()-1;k>=i&&nums[k]<=nums[j];--k); // 定位大数的位置k
                t=nums[k],nums[k]=nums[j],nums[j]=t; // 交换大小数
                for(j=i,k=nums.size()-1;j<k;++j,--k) t=nums[j],nums[j]=nums[k],nums[k]=t; // 逆序[i, end]
                return;
            }
        }
        for(i=0,j=nums.size()-1;i<j;i++,j--) k=nums[i],nums[i]=nums[j],nums[j]=k;
    }
};