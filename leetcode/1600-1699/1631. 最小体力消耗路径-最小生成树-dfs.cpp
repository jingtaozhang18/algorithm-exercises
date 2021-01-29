// https://leetcode-cn.com/problems/path-with-minimum-effort/
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
    // 仿照二叉树的遍历，需要添加一个父id标识，防止回退
    int dfs(int id, vector<vector<pair<int,int>>>&edges, int ans, int father, int tar){
      int na=INT_MAX;
      if(id==tar) return ans;
      for(auto nid:edges[id]){
        if(nid.first==father) continue;
        na=min(na, dfs(nid.first, edges, max(ans,nid.second), id, tar));
      }
      return na;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
      int i,j,m=heights.size(),n=heights[0].size(),ans=0,a,b,d;
      junion jun(m*n);
      auto tupleCmp = [](const auto &e1, const auto &e2){
            auto&& [x1, y1, d1] = e1;
            auto&& [x2, y2, d2] = e2;
            return d1 > d2;
      };
      // 将所有的边加入到优先级队列中去
      priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(tupleCmp)> que(tupleCmp);
      vector<vector<pair<int,int>>> edges(m*n, vector<pair<int, int>>());
      for(i=0;i<m;++i){
        for(j=0;j<n;++j){
          if(i>0) que.emplace((i-1)*n+j, i*n+j, abs(heights[i-1][j]-heights[i][j]));
          if(j>0) que.emplace(i*n+j-1, i*n+j, abs(heights[i][j-1]-heights[i][j]));
        }
      }
      // 构建联通左上角和右下角的最小生成树
      while(jun.find(0)!=jun.find(m*n-1)){
        if(que.empty()) cout<<"empty"<<endl;
        auto t = que.top();
        a=get<0>(t), b=get<1>(t), d=get<2>(t);
        que.pop();
        // cout<<a<<" "<<b<<" "<<d<<endl;
        if(jun.find(a)!=jun.find(b)){
          edges[a].push_back(make_pair(b, d));
          edges[b].push_back(make_pair(a, d));
          jun.merge(a, b);
        }
      }
      // 遍历dfs生成树，找到左上角到右下角的路径，并返回最小体力
      ans=dfs(0,edges,0,-1,m*n-1);
      return ans;
    }
};