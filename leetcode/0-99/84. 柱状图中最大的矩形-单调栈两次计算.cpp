// https://leetcode-cn.com/problems/largest-rectangle-in-histogram/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // 单调栈
        stack<int> sta;
        vector<int> left(heights.size(), -1);
        vector<int> right(heights.size(), -1);
        int i,j,ans=0;
        for(i=0;i<heights.size();++i){ // 单增栈
            while(!sta.empty()&&heights[i]<heights[sta.top()]){
                right[sta.top()]=i; sta.pop();
            }
            sta.push(i);
        }
        while(!sta.empty()) {right[sta.top()]=heights.size(); sta.pop();}
        for(i=heights.size()-1;i>=0;--i){
            while(!sta.empty()&&heights[i]<heights[sta.top()]){
                left[sta.top()]=i; sta.pop();
            }
            sta.push(i);
        }
        while(!sta.empty()) {left[sta.top()]=-1; sta.pop();}
        for(i=0;i<heights.size();++i){
            ans=max((right[i]-left[i]-1)*heights[i], ans);
        }
        return ans;
    }
};