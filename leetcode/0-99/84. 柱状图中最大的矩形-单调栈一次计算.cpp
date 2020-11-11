// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 单调栈
        stack<int> sta;
        vector<int> left(heights.size(), -1);
        vector<int> right(heights.size(), heights.size());
        int i,j,ans=0;
        for(i=0;i<heights.size();++i){ // 单增栈
            while(!sta.empty()&&heights[i]<heights[sta.top()]){
                right[sta.top()]=i; sta.pop();
            }
            left[i] = (sta.empty() ? -1 : sta.top());
            sta.push(i);
        }
        for(i=0;i<heights.size();++i){
            ans=max((right[i]-left[i]-1)*heights[i], ans);
        }
        return ans;
    }
};