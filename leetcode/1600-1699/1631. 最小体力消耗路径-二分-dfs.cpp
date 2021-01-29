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
    int dir[4][2]{-1,0,1,0,0,-1,0,1};
    // 判断在tar的限制下能否从左上角遍历到右下角
    bool dfs(int a, int b, vector<vector<int>>& heights, vector<vector<bool>>& color, int m, int n, int tar){
      if(a==m-1&&b==n-1) return true;
      if(color[a][b]) return false;
      color[a][b]=1;
      int x,y;
      for(int i=0;i<4;++i){
        x=a+dir[i][0];
        y=b+dir[i][1];
        if(x>=0&&x<m&&y>=0&&y<n){
          if(abs(heights[a][b]-heights[x][y])<=tar){
            if(dfs(x,y,heights,color,m,n,tar)) return true;
          } 
        }
      }
      return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
      int m=heights.size(), n=heights[0].size(), i, j, l=0, r=1e6, tar;
      vector<vector<bool>> color(m, vector<bool>(n));
      // 二分选找最终答案
      while(l<=r){
        tar=(l+r)>>1;
        for(i=0;i<m;++i)for(j=0;j<n;++j) color[i][j]=false;
        if(dfs(0,0,heights,color,m,n,tar)) r=tar-1;
        else l=tar+1;
      }
      return l;
    }
};