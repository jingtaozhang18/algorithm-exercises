// https://leetcode-cn.com/problems/zai-pai-xu-shu-zu-zhong-cha-zhao-shu-zi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLR(vector<int>& nums, int target, bool L){ // 找到一个数字在数组中出现的最左位置
        int l=0, r=nums.size()-1, c;
        while(l<=r){
            c=(l+r)>>1;
            if(nums[c]<target) l=c+1;
            else if(nums[c]>target) r=c-1;
            else if(L)r=c-1; else l=c+1;
        }
        return L?l:r;
    }
    int search(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        int l=findLR(nums,target,true);
        if(0<=l&&l<nums.size()&&nums[l]!=target) return 0;
        int r=findLR(nums,target,false);
        // cout<<l<<" "<<r<<endl;
        return r-l+1;
    }
};

// 复习
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left, right, center, a, b, m=nums.size();
        if(m==0) return 0;
        left=0, right=m-1;
        while(left<=right){
            center=left+(right-left)/2;
            if(nums[center]<=target) left=center+1;
            else right=center-1;
        }
        a=right; // 右边界
        if(a<0) return 0;
        
        left=0, right=m-1;
        while(left<=right){
            center=left+(right-left)/2;
            if(nums[center]>=target) right=center-1;
            else left=center+1;
        }
        b=left; // 左边界
        return a-b+1;
    }
};
