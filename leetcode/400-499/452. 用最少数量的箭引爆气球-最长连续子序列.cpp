// https://leetcode-cn.com/problems/minimum-number-of-arrows-to-burst-balloons/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int i, n=points.size(),ans=0,l,c,r;
        vector<int> mem(n+1, INT_MAX);
        sort(points.begin(), points.end());
        for(i=0;i<n;++i){
            l=1,r=ans;
            while(l<=r){c=(l+r)>>1; if(mem[c]<points[i][0]) l=c+1; else r=c-1;}
            ans=max(ans,l), mem[l]=min(mem[l], points[i][1]);
        }
        return ans;
    }
};