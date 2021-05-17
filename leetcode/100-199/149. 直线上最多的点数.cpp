// https://leetcode-cn.com/problems/max-points-on-a-line/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        unordered_map<double, int> mp;
        int i, j, n=points.size(), x1, x2, y1, y2, ans=0, ta, same_point;
        for(i=0;i<n;++i){
            mp.clear(); same_point=0, ta=0;
            for(j=0;j<n;++j){
                x1=points[i][0], x2=points[j][0];
                y1=points[i][1], y2=points[j][1];
                if(x1==x2&&y1==y2) same_point++;
                else if(x1==x2) mp[INT_MAX]++;
                else if(y1==y2) mp[0]++;
                else mp[double(y1-y2)/(x1-x2)]++;
            }
            for(auto p:mp){
                ta=max(ta, p.second);
            }
            ans=max(ta+same_point, ans);
        }
        return ans;
    }
};