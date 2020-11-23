// https://leetcode-cn.com/problems/non-overlapping-intervals/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int i, n=intervals.size(),ans=0,l,c,r;
        vector<int> mem(n+1, INT_MAX);
        sort(intervals.begin(), intervals.end()); // 错误点： 排序
        for(i=0;i<n;++i){
            l=1,r=ans;
            while(l<=r){c=(l+r)>>1; if(mem[c]<=intervals[i][0]) l=c+1; else r=c-1;}
            ans=max(ans,l), mem[l]=min(mem[l], intervals[i][1]);
        }
        return n-ans;
    }
};