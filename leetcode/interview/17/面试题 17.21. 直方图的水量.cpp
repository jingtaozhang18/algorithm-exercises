// https://leetcode-cn.com/problems/volume-of-histogram-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
      int size=height.size();
      if(size<2) return 0;
      int maxl=height[0], maxr=height[size-1], l=1, r=size-2, ans=0;
      while(l<=r){
        if(maxl<maxr){ // 错误点： 这个应该根据左右的短板进行判断，左边还是右边的水位高度可以计算
          ans+=max(0, maxl-height[l]);
          maxl=max(maxl, height[l]);
          l++;
        }else{
          ans+=max(0, maxr-height[r]);
          maxr=max(maxr, height[r]);
          r--;
        }
      }
      return ans;
    }
};

// 复习
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3) return 0;
        int left=0, right=height.size()-1, maxl=height[left], maxr=height[right], ans=0;
        ++left, --right;
        while(left<=right){
            if(maxl<maxr){
                ans+=max(0, maxl-height[left]);
                maxl=max(maxl, height[left++]);
            }else{
                ans+=max(0, maxr-height[right]);
                maxr=max(maxr, height[right--]);
            }
        }
        return ans;
    }
};