// https://leetcode-cn.com/problems/route-between-nodes-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
      map<int, vector<int>> mp;
      for(auto e:graph)
      {
        mp[e[0]].push_back(e[1]);
      }
      vector<short> color(n, 0); // 0还未探索，1被发现，2已探索
      queue<int> que;
      que.push(start);
      color[start]=1;
      while(!que.empty())
      {
        int a=que.front();
        que.pop();
        for(auto e:mp[a])
        {
          if(color[e]==0) {
            color[e]=1; que.push(e);
          }
          if(e==target) return true;
        }
        color[a]=2;
      }
      return false;
    }
};