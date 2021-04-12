// https://leetcode-cn.com/problems/Db3wC1/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dir[5][2]={1,0,0,1,0,0,-1,0,0,-1};
    bool mem[105][55][55][2][2]={false}; // 记录是否访问到了
    
    // t 临时， f永远 从t时刻向t+1时刻进发
    bool dfs(vector<vector<string>>& maze, int i, int j, int t, bool ba, bool bb){ 
        if(mem[t][i][j][ba][bb]) return false; // 访问过了，不行，不再尝试
        mem[t][i][j][ba][bb]=true; // 该状态已经进行了实验，无需再进行
        int st=maze.size(), m=maze[0].size(), n=maze[0][0].size();
        if(t<st&&i==m-1&&j==n-1) return true;
        ++t; if(t==st) return false;
        if(st-t<m-1-i+n-1-j) return false; // 时间不够
        int x, y, k;
        for(k=0;k<5;++k){
            x=i+dir[k][0];
            y=j+dir[k][1];
            if(x>=0&&x<m&&y>=0&&y<n){
                if(maze[t][x][y]=='.') {
                    if(dfs(maze, x, y, t, ba, bb)) return true;
                }
                else{
                    if(ba){
                        if(dfs(maze, x, y, t, false, bb)) return true;
                    }
                    if(bb){
                        // 关键点，永久消除魔法可以在之后的任何时间节点出现在该位置上
                        for(int l=t; l<st; l++){
                            if(dfs(maze, x, y, l, ba, false)) return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool escapeMaze(vector<vector<string>>& maze) {
        int t=maze.size(), m=maze[0].size(), n=maze[0][0].size();
        return dfs(maze, 0,0,0,true, true);
    }
};