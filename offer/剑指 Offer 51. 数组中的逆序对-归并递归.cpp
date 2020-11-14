// https://leetcode-cn.com/problems/shu-zu-zhong-de-ni-xu-dui-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(vector<int>& nums, int left, int right){ // center=(left+right)>>1 在[left, right] 范围内进行归并排序 [left, center][center+1, right] 进行合并
        int ans=0, center=(left+right)>>1;
        if(right-left+1>=2) {
            ans+=jgo(nums, left, center);
            ans+=jgo(nums, center+1, right); // 数量大于2继续进行拆分
        }else if(right==left) return ans;
        // 在左右两侧都已经有序的情况下
        int a=left, b=center+1, i=0,acc=0;
        vector<int> tmp(right-left+1);
        while(a<=center&&b<=right){
            if(nums[a]>nums[b]) {
                acc+=(center-a+1), tmp[i++]=nums[b++];
            } else if(nums[a]==nums[b]) tmp[i++]=nums[a++]; // 右侧的数字需要先留下来
            else tmp[i++]=nums[a++];
        }
        ans+=acc;
        while(a<=center) tmp[i++]=nums[a++];
        while(b<=right) tmp[i++]=nums[b++];
        for(i=0;i<tmp.size();++i) {
            nums[left++]=tmp[i];
        }
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return jgo(nums, 0, nums.size()-1);
    }
};