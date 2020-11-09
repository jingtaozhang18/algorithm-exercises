// https://leetcode-cn.com/problems/k-closest-points-to-origin/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> ans;
        // warining 优先级队列的比较函数是pair的比较函数，慎重使用，该题比较特殊，second相当于没有作用
        priority_queue<pair<int, int>> pq; // 距离，编号
        int i,j;
        for(i=0;i<K;++i){
            pq.emplace(pow(points[i][0], 2)+pow(points[i][1], 2), i);
        }
        for(;i<points.size();++i){
            if(pow(points[i][0], 2)+pow(points[i][1], 2)<pq.top().first)
                pq.pop(), pq.emplace(pow(points[i][0], 2)+pow(points[i][1], 2), i);
        }
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};