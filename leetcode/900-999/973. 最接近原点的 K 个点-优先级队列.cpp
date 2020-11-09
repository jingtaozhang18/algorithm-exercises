// https://leetcode-cn.com/problems/k-closest-points-to-origin/
#include<bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    bool operator<(const point& other) const{
        return x*x+y*y<other.x*other.x+other.y*other.y;
    }
    point(int x, int y):x(x),y(y){};
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        priority_queue<point, vector<point>> pq;
        int i,j;
        for(i=0;i<points.size();++i){
            point p(points[i][0], points[i][1]);
            pq.push(p);
            if(pq.size()>K) pq.pop();
        }
        while(!pq.empty()){
            point p=pq.top();pq.pop();
            vector<int>t(2,0); t[0]=p.x, t[1]=p.y;
            ans.push_back(t);
        }
        return ans;
    }
};