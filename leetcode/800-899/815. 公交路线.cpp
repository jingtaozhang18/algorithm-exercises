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

// 复习，好像没有第一遍做到好
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0; // 注意特例情况
        // 统计公家车之间的交点
        unordered_map<int, unordered_set<int>> mp;
        int index=0;
        for(auto &bus:routes) {for(auto &s:bus) mp[s].insert(index); index++;}
        // 构建邻接矩阵
        unordered_map<int, unordered_set<int>> mp_bus;
        for(auto &p:mp) for(auto &b:p.second) for(auto &bse:p.second) if(b!=bse) mp_bus[b].insert(bse);
        if(mp[target].empty()) return -1; // 没有公交车经过
        // bfs搜索
        unordered_map<int, int> deep;
        queue<int> que; // bfs search
        for(auto &p:mp[source]) {deep[p]=1; que.push(p);}
        while(que.size()){ // 换乘公交
            int t=que.front(); que.pop();
            for(auto&p:mp_bus[t]){ // 
                if(deep[p]==0||deep[p]>deep[t]+1){
                    deep[p]=deep[t]+1;
                    que.push(p);
                }
            }
        }
        int ans=INT_MAX;
        for(auto&p:mp[target]) if(deep[p]!=0) ans=min(ans, deep[p]);
        return ans==INT_MAX?-1:ans;
    }
};
