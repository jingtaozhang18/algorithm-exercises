// https://leetcode-cn.com/problems/bus-routes/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
      routes.push_back(vector<int>{source});
      routes.push_back(vector<int>{target});
      int i, j, n=routes.size();
      vector<set<int>> r;
      for(i=0;i<n;++i) r.push_back(set<int>(routes[i].begin(), routes[i].end()));
      vector<vector<bool>> arr(n, vector<bool>(n, false));
      for(i=0; i<n; ++i){
        for(j=i+1; j<n; ++j){
          for(auto p:r[i]) {
            if(r[j].count(p)){
              arr[i][j]=true, arr[j][i]=true; 
              break;
            }
          }
        }
      }
      vector<int> color(n); // bfs
      color[n-2] = 1; // 被访问到了
      queue<pair<int, int>> que;
      que.push(make_pair(n-2, 0));
      while(que.size()){
        int s = que.front().first, l = que.front().second;
        que.pop();
        for(i=0;i<n;++i){
          if(arr[s][i]){
            if(color[i]==0){
              if(i==n-1) return l;
              color[i]=1;
              que.push(make_pair(i, l+1));
            }
          }
        }
      }
      return -1;
    }
};