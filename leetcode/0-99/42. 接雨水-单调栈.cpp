// https://leetcode-cn.com/problems/trapping-rain-water/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=1) return 0;
        stack<int> sta;
        int i,j,k,ans=0,size=height.size();
        for(i=0;i<size;++i){
            k=0;
            while(!sta.empty()&&height[i]>=height[sta.top()]){ // 单减栈
            	// 左边届作为限制
                j=sta.top();
                sta.pop();
                ans+=(height[j]-k)*(i-j-1);
                k=height[j];
            }
            // 右边界作为限制
            if(!sta.empty()){ans+=(height[i]-k)*(i-sta.top()-1);}
            sta.push(i);
        }
        return ans;
    }
};