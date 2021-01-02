// https://leetcode-cn.com/problems/robot-in-a-grid-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<bool>> seen;
    vector<int> pos{1,0,0,1};
    int m,n;
    bool jgo(vector<vector<int>>& arr, int i, int j){
        // cout<<i<<" "<<j<<endl;
        ans.push_back(vector<int>{i,j});
        if(i==m-1&&j==n-1) return true;
        int x,y,k;
        for(k=0;k<2;++k) {
            x=i+pos[2*k], y=j+pos[2*k+1];
            if(x<m&&y<n&&arr[x][y]==0&&seen[x][y]==false){
                seen[x][y]=true;
                if(jgo(arr, x, y)) return true;
                // seen[x][y]=false; // 超时点：没必要再走了
            }
        }
        ans.pop_back();
        return false;
    }
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        ans.clear();
        m=obstacleGrid.size(), n=obstacleGrid[0].size();
        seen=vector(m, vector<bool>(n, false)); // 全局变量的赋值
        seen[0][0]=true;
        // 左上角机器人的位置也有可能有障碍物
        if(obstacleGrid[0][0]==0&&jgo(obstacleGrid, 0, 0)) return ans;
        ans.clear();
        return ans;
    }
};