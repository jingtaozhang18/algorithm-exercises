// https://leetcode-cn.com/problems/trapping-rain-water/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        if(size<2) return 0;
        // [left, right], lmax为[0,left)的最大值， rmax同理
        int left=0,lmax=0,right=size-1,rmax=0,ans=0;
        while(left<=right){
            if(height[left]<height[right]){ // 保证了右边不漏，位置left的储水量由lmax决定
                ans+=max(0, lmax-height[left]);
                lmax=max(lmax, height[left++]);
            }else{
                ans+=max(0, rmax-height[right]);
                rmax=max(rmax, height[right--]);
            }
        }
        return ans;
    }
};