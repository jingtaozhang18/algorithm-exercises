// https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dir[4][2]={-1,0,1,0,0,-1,0,1};
    void jgo(vector<vector<int>>& dp, vector<vector<int>>& matrix, int i, int j, int& ans){ // 计算[i][j]的最大长度
        int x,y,k,m=matrix.size(),n=matrix[0].size(),mav=0,ii=-1,jj=-1;
        dp[i][j]=0; // 错误点：标记已经探索过，避免死循环
        for(k=0;k<4;++k){
            x=i+dir[k][0], y=j+dir[k][1];
            if(0<=x&&x<m&&0<=y&&y<n){ // 在边界内
                if(matrix[x][y]<matrix[i][j]){ // 错误点，应该只关心从这个点出发的可行点
                     if(dp[x][y]==-1) jgo(dp, matrix, x, y, ans);
                     if(dp[x][y]>mav) mav=dp[x][y], ii=x, jj=y;
                }
            }
        }
        dp[i][j]=mav+1;
        ans=max(dp[i][j], ans);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return 0;
        int m=matrix.size(),n=matrix[0].size(),ans=0,i,j;
        vector<vector<int>> dp(m, vector<int>(n, -1)); // 记录从当前位置可以扩展的最长路径
        for(i=0;i<m;++i) for(j=0;j<n;++j) jgo(dp,matrix,i,j,ans);
        return ans;
    }
};