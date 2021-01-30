// https://leetcode-cn.com/problems/swim-in-rising-water/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int i, j, x, y, m=grid.size(), n=grid[0].size();
        auto cmp = [](const vector<int>& a, const vector<int>& b){
          return a[2]>b[2];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> que(cmp);
        vector<vector<int>> arr(grid);
        for(i=0;i<m;++i)for(j=0;j<n;++j) arr[i][j]=INT_MAX;
        que.push(vector<int>{0,0,grid[0][0]});
        int dir[4][2]{-1,0,1,0,0,-1,0,1};
        while(!que.empty()&&arr[m-1][n-1]==INT_MAX){
          auto t=que.top(); que.pop();
          for(i=0;i<4;++i){
            x=t[0]+dir[i][0], y=t[1]+dir[i][1];
            if(x>=0&&x<m&&y>=0&&y<n){
              if(arr[x][y]>max(t[2], grid[x][y])){
                arr[x][y]=max(t[2], grid[x][y]);
                que.push(vector<int>{x,y,arr[x][y]});
              }
            }
          }
        }
        return arr[m-1][n-1];
    }
};


// 相同的思路，使用tuple可以显著提升速度
// vector	通过	16 ms	8.3 MB	C++
// tuple 	通过	44 ms	10.3 MB C++
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int i, j, x, y, m=grid.size(), n=grid[0].size();
        auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b){
          return get<2>(a)>get<2>(b);
        };
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> que(cmp);
        vector<vector<int>> arr(grid);
        for(i=0;i<m;++i)for(j=0;j<n;++j) arr[i][j]=INT_MAX;
        que.emplace(0,0,grid[0][0]);
        int dir[4][2]{-1,0,1,0,0,-1,0,1};
        while(!que.empty()&&arr[m-1][n-1]==INT_MAX){
          auto t=que.top(); que.pop();
          for(i=0;i<4;++i){
            x=get<0>(t)+dir[i][0], y=get<1>(t)+dir[i][1];
            if(x>=0&&x<m&&y>=0&&y<n){
              if(arr[x][y]>max(get<2>(t), grid[x][y])){
                arr[x][y]=max(get<2>(t), grid[x][y]);
                que.emplace(x,y,arr[x][y]);
              }
            }
          }
        }
        return arr[m-1][n-1];
    }
};