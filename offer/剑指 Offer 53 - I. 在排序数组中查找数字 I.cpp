// https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLR(vector<int>& nums, int target, bool L){ // 找到一个数字在数组中出现的最左位置
        if(nums.size()==0) return -1;
        int l=0, r=nums.size()-1, c;
        while(l<r-1){ // 因为有等于center的操作，不能直接使用l<r
            c=(l+r)>>1;
            if(nums[c]<target) l=c+1;
            else if(nums[c]>target) r=c-1;
            else if(L)r=c; else l=c; // 最左侧，将右边界移到center处
        }
        if(L) if(nums[l]==target) return l; else if(nums[r]==target) return r; else return -1;
        else if(nums[r]==target) return r; else if(nums[l]==target) return l; else return -1;
    }
    int search(vector<int>& nums, int target) {
        int l=findLR(nums,target,true);
        int r=findLR(nums,target,false);
        return l!=-1?r-l+1:0;
    }
};