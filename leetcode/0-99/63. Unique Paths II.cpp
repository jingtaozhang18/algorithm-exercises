// https://leetcode-cn.com/problems/unique-paths-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size(), i, j;
        if(obstacleGrid[0][0]||obstacleGrid[m-1][n-1]) return 0;
        int dp[m][n];
        for(i=0;i<m;++i)for(j=0;j<n;++j) dp[i][j]=0;
        dp[0][0]=1;
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(obstacleGrid[i][j]==0){
                    if(i&&obstacleGrid[i-1][j]==0) dp[i][j]+=dp[i-1][j];
                    if(j&&obstacleGrid[i][j-1]==0) dp[i][j]+=dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};