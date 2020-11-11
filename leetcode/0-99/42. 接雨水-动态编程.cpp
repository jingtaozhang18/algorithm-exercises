// https://leetcode-cn.com/problems/trapping-rain-water/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
    	// 记录每个位置左右两边的雨水量
        if(height.size()<=1) return 0;
        int i,ans=0,size=height.size();
        vector<int> left(size);
        vector<int> right(size);
        for(left[0]=0,i=1;i<size;++i) left[i]=max(left[i-1], height[i-1]);
        for(right[size-1]=0,i=size-2;i>=0;--i) right[i]=max(right[i+1], height[i+1]);
        for(i=0;i<size;++i) ans+=max(min(left[i], right[i])-height[i], 0);
        return ans;
    }
};