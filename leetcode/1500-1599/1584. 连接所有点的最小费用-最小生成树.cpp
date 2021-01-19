// https://leetcode-cn.com/problems/min-cost-to-connect-all-points/
#include<bits/stdc++.h>
using namespace std;

struct junion{
  vector<int> mem;
  junion(int n):mem(vector<int>(n)){
    for(int i=0;i<n;++i) mem[i]=i;
  }
  int find(int i){
    if(mem[i]!=i) mem[i]=find(mem[i]);
    return mem[i];
  }
  void merge(int i, int j){
    i=find(i), j=find(j);
    if(i!=j) mem[i]=j;
  }
};
struct edge{
  int i, j, d;
  edge(int i, int j, int d):i(i),j(j),d(d){}
  bool operator<(const edge& other) const{
    return d>other.d;
  }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
      int i,j,d,size=points.size(),ans=0;
      priority_queue<edge> que;
      junion ju(size);
      for(i=0;i<size;++i){
        for(j=i+1;j<size;++j){
          d=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
          que.push(edge(i,j,d));
        }
      }
      while(!que.empty()){
        i=que.top().i, j=que.top().j, d=que.top().d;
        que.pop();
        if(ju.find(i)==ju.find(j)) continue;
        ans+=d;
        ju.merge(i,j);
      }
      return ans;
    }
};