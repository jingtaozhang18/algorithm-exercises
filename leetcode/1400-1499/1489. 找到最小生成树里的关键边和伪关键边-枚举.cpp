// https://leetcode-cn.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&a, vector<int>&b){
  return a[2]<b[2];
}
struct junion{
  vector<int> arr;
  int size;
  junion(int n):arr(vector<int>(n)),size(n){for(int i=0;i<n;++i) arr[i]=i;}
  int find(int i){
    if(arr[i]!=i) arr[i]=find(arr[i]);
    return arr[i];
  }
  void reset(){size=arr.size(); for(int i=0;i<size;++i) arr[i]=i;}
  void merge(int i, int j){
    i=find(i);
    j=find(j);
    if(i!=j) arr[i]=j, size--;
    // cout<<i<<" "<<j<<" "<<size<<endl;
  }
};
// 考虑情况 一条边有三种情况：
// （1） 不在最小生成树中                          换言之， 先加入该边，无法组成最小生成树
// （2） 在某个最小生成树中，但不在所有的最小生成树中
// （3） 在所有的最小生成树中                       换言之，少了它不能构成最小生成树 
class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
      vector<vector<int>> edges_copy(edges);
      sort(edges.begin(), edges.end(), cmp);
      int i, j, size=edges.size(),a,b,sum,ms;
      junion ju(n);
      vector<vector<int>> ans{vector<int>(0), vector<int>(0)};
      // 建立映射关系
      unordered_map<int, int> mp;
      for(i=0;i<size;++i){
        for(j=0;j<size;++j) if(edges_copy[i]==edges[j]) break;
        mp[j]=i;
      }
      // 寻找关键边
      for(i=-1;i<size;++i){
        sum=0;
        ju.reset();
        for(j=0;j<size;++j){
          if(j==i) continue;
          a=edges[j][0], b=edges[j][1];
          if(ju.find(a)==ju.find(b)) continue;
          else {sum+=edges[j][2]; ju.merge(a, b);}
        }
        if(i==-1) ms=sum;
        else{
          if(sum>ms||ju.size>1) ans[0].push_back(mp[i]); // 少了他不行，则该边一定是关键边
          else{
            // 寻找伪关键边(前提不是关键边) 优先考虑这条边，如果最终仍能构成最小生成树，则该边没有出现在所有的最小生成树中
            sum=0;
            ju.reset();
            // 优先考虑
            a=edges[i][0], b=edges[i][1];
            sum+=edges[i][2]; ju.merge(a, b);
            for(j=0;j<size;++j){
              if(j==i) continue;
              a=edges[j][0], b=edges[j][1];
              if(ju.find(a)==ju.find(b)) continue;
              else {sum+=edges[j][2]; ju.merge(a, b);}
            }
            if(sum==ms&&ju.size==1) ans[1].push_back(mp[i]);
          }
        }
      }
      return ans;
    }
};