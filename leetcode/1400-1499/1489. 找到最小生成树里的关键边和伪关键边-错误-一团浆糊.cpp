// https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&a, vector<int>&b){
  return a[2]<b[2];
}

class Solution {
public:
    vector<int> mem; // 存储, 1关键边，-1伪关键边
    int find(vector<int>& arr, int i){
      if(arr[i]!=i) arr[i]=find(arr, arr[i]);
      return arr[i];
    }
    void merge(vector<int>& arr, int i, int j){
      i=find(arr, i);
      j=find(arr, j);
      if(i!=j) arr[i]=j;
    }
    void jgo_go(vector<vector<int>>&edges, vector<int>&arr, int i){
      int size=edges.size(), j, a, b;
      if(i==size) return;
      a=edges[i][0], b=edges[i][1];
      if(find(arr, a)==find(arr, b)) mem[i]=-1;
      else {if(mem[i]!=-1) mem[i]=1; merge(arr, a, b);}
      if(i+1==size||edges[i+1][2]==edges[i][2]) jgo_go(edges, arr, i+1);
      else 
        jgo(edges, arr, i+1);
    }
    void jgo(vector<vector<int>>&edges, vector<int>&arr, int i){
      int size=edges.size(),j;
      for(j=i;j<size;++j){
        if(j==i||edges[j][2]==edges[j-1][2]){
          vector<int> arr_copy(arr);
          swap(edges[i], edges[j]);
          cout<<i<<" "<<j<<endl;
          jgo_go(edges, arr_copy, i);
          swap(edges[i], edges[j]);
        }
      }
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
      sort(edges.begin(), edges.end(), cmp);
      int i;
      mem=vector<int>(edges.size());
      vector<int> arr(n);
      for(i=0;i<n;++i) arr[i]=i;
      vector<vector<int>> ans{vector<int>(0), vector<int>(0)};
      jgo(edges, arr, 0);
      for(i=0;i<edges.size();++i) {
        if(mem[i]==1) ans[0].push_back(i);
        else if(mem[i]==-1) ans[1].push_back(i);
      }
      return ans;
    }
};