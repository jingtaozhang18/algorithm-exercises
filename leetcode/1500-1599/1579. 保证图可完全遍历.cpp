// https://leetcode-cn.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
#include<bits/stdc++.h>
using namespace std;

struct junion{
  vector<int> mem;
  int size;
  junion(junion& jun):mem(jun.mem),size(jun.size){}
  junion(int n):mem(vector<int>(n)),size(n){for(int i=0;i<size;++i) mem[i]=i;}
  int find(int i){if(mem[i]!=i) mem[i]=find(mem[i]); return mem[i];}
  void merge(int i, int j){i=find(i), j=find(j); if(i!=j) mem[i]=j,--size;}
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
      sort(edges.rbegin(), edges.rend());
      junion jun(n);
      int i, ans=0, size=edges.size();
      for(i=0;i<size;++i){
        if(edges[i][0]!=3) break;
        if(jun.find(edges[i][1]-1) != jun.find(edges[i][2]-1)){
          jun.merge(edges[i][1]-1, edges[i][2]-1);
          ans++;
        }
      }
      junion ojun(jun);
      for(;i<size;++i){
        if(edges[i][0]!=2) break;
        if(jun.find(edges[i][1]-1) != jun.find(edges[i][2]-1)){
          jun.merge(edges[i][1]-1, edges[i][2]-1);
          ans++;
        }
      }
      if(jun.size!=1) return -1;
      for(;i<size;++i){
        if(ojun.find(edges[i][1]-1) != ojun.find(edges[i][2]-1)){
          ojun.merge(edges[i][1]-1, edges[i][2]-1);
          ans++;
        }
      }
      if(ojun.size!=1) return -1;
      return size-ans;
    }
};