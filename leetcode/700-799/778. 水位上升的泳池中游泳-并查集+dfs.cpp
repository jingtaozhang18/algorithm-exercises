// https://leetcode-cn.com/problems/swim-in-rising-water/
#include<bits/stdc++.h>
using namespace std;

struct junion{
    vector<int> arr;
    junion(int size):arr(vector<int>(size)){for(int i=0;i<size;++i)arr[i]=i;}
    int find(int i){if(arr[i]!=i) arr[i]=find(arr[i]); return arr[i];}
    void merge(int i, int j){i=find(i), j=find(j); if(i!=j) arr[i]=j;}
};
class Solution {
public:
    int dfs(vector<vector<pair<int, int>>>& mst, int id, int tar, int ans, int father){
        if(id==tar) return ans;
        int res=INT_MAX;
        for(auto t:mst[id]){
            if(t.first==father) continue;
            res=min(res, dfs(mst, t.first, tar, max(ans, t.second), id));
        }
        return res;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int i, j, m=grid.size(), n=grid[0].size();
        junion jun(m*n);
        auto cmp = [](const vector<int>&a, const vector<int>&b){
            return a[2]>b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> que(cmp);
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(i>0) que.push(vector<int>{(i-1)*n+j, i*n+j, max(grid[i-1][j], grid[i][j])});
                if(j>0) que.push(vector<int>{i*n+j-1, i*n+j, max(grid[i][j-1], grid[i][j])});
            }
        }
        vector<vector<pair<int, int>>> mst(m*n);
        while(jun.find(0)!=jun.find(m*n-1)){
            auto t=que.top();
            que.pop();
            if(jun.find(t[0])!=jun.find(t[1])){
                jun.merge(t[0], t[1]);
                mst[t[0]].push_back(make_pair(t[1], t[2]));
                mst[t[1]].push_back(make_pair(t[0], t[2]));
            }
        }
        return dfs(mst, 0, m*n-1, 0, -1);
    }
};

// 同样的思路，使用tuple可以提升速度
// vector 116 ms	19 MB
// tuple  36 ms	    13.1 MB
class Solution {
public:
    int dfs(vector<vector<pair<int, int>>>& mst, int id, int tar, int ans, int father){
        if(id==tar) return ans;
        int res=INT_MAX;
        for(auto t:mst[id]){
            if(t.first==father) continue;
            res=min(res, dfs(mst, t.first, tar, max(ans, t.second), id));
        }
        return res;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int i, j, m=grid.size(), n=grid[0].size(), a,b,d;
        junion jun(m*n);
        auto cmp = [](const tuple<int, int, int>&a, const tuple<int, int, int>&b){
            return get<2>(a)>get<2>(b);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> que(cmp);
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(i>0) que.emplace((i-1)*n+j, i*n+j, max(grid[i-1][j], grid[i][j]));
                if(j>0) que.emplace(i*n+j-1, i*n+j, max(grid[i][j-1], grid[i][j]));
            }
        }
        vector<vector<pair<int, int>>> mst(m*n);
        while(jun.find(0)!=jun.find(m*n-1)){
            auto t=que.top();
            que.pop();
            a=get<0>(t), b=get<1>(t), d=get<2>(t);
            if(jun.find(a)!=jun.find(b)){
                jun.merge(a, b);
                mst[a].push_back(make_pair(b, d));
                mst[b].push_back(make_pair(a, d));
            }
        }
        return dfs(mst, 0, m*n-1, 0, -1);
    }
};