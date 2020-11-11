// https://leetcode-cn.com/problems/container-with-most-water/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 贪心
        int i,j,k=0;
        for(i=0,j=height.size()-1;i<j;){
            k=max(k, min(height[i], height[j])*(j-i));
            if(height[i]<=height[j]) ++i;
            else --j;
        }
        return k;
    }
};