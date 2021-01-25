// https://leetcode-cn.com/problems/regions-cut-by-slashes/
#include<bits/stdc++.h>
using namespace std;

struct junion{
  vector<int> mem;
  int size;
  junion(int n):mem(vector<int>(n)),size(n){for(int i=0;i<n;++i) mem[i]=i;}
  int find(int i){
    if(mem[i]!=i) mem[i]=find(mem[i]); // 错误点：应该是find(mem[i])
    return mem[i];
  }
  void merge(int i, int j){
    i=find(i), j=find(j); 
    if(i!=j) mem[i]=j, --size;
  }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
      int i,j,size=grid.size(),a,b,c;
      junion jun(size*size*4);
      for(i=0;i<size;++i){
        for(j=0;j<size;++j){
          a=(i*size+j)*4;
          if(grid[i][j]=='\\'){
            jun.merge(a, a+3);
            jun.merge(a+1, a+2);
          }else if(grid[i][j]=='/'){
            jun.merge(a, a+1);
            jun.merge(a+2, a+3);
          }else{
            jun.merge(a, a+1);
            jun.merge(a+1, a+2);
            jun.merge(a+2, a+3);
          }
          if(j+1<size){ // 错误点： 不是j<size
            b=(i*size+j+1)*4; // 右侧方格
            jun.merge(a+3,b+1);
          }
          if(i+1<size){
            c=((i+1)*size+j)*4;
            jun.merge(a+2, c);
          }
        }
      }
      return jun.size;
    }
};