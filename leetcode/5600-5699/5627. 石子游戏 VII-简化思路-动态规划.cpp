// https://leetcode-cn.com/problems/stone-game-vii/
#include<bits/stdc++.h>
using namespace std;

// 我们最关心的是在某状态下先走的人能获得的最大收益，而不是现在谁先走
class Solution {
public:
    int stoneGameVII(vector<int>& stones) {
        int size=stones.size(),i,j,diff;
        vector<int> arr;
        arr.push_back(0);
        for(auto s:stones) arr.push_back(arr.back()+s);
        vector<vector<int>> dp(size, vector<int>(size, 0)); // dp[i][j] 表示[i, j]有游戏权的人能得到的最大差值
        for(diff=1;diff<size;++diff){
            for(i=0;i<size-diff;++i){
                j=i+diff;
                dp[i][j]=max(
                    arr[j]-arr[i]-dp[i][j-1], // 去掉右边的
                    arr[j+1]-arr[i+1]-dp[i+1][j] // 去掉左边的
                );
            }
        }
        return dp[0][size-1];
    }
};