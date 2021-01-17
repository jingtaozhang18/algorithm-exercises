// https://leetcode-cn.com/problems/most-stones-removed-with-same-row-or-column/
#include<bits/stdc++.h>
using namespace std;

struct ju{
  vector<int> mem;
  ju(int n):mem(vector<int>(n)){
    for(int i=0;i<n;++i) mem[i]=i;
  }
  int find(int i){
    if(mem[i]!=i) mem[i]=find(mem[i]);
    return mem[i];
  }
  void merge(int i, int j){
    i=find(i);
    j=find(j);
    if(i!=j) mem[i]=j;
  }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
      int i,j,size=stones.size();
      ju junion(size);
      for(i=0;i<size;++i){
          for(j=i+1;j<size;++j){
            if(stones[i][0]==stones[j][0]||stones[i][1]==stones[j][1]) junion.merge(i, j);
          }
      }
      set<int> st;
      for(i=0;i<size;++i){
        st.insert(junion.find(i));
      }
      return size-st.size();
    }
};