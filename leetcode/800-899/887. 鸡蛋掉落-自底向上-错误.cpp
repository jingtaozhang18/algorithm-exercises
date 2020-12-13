// https://leetcode-cn.com/problems/super-egg-drop/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N, INT_MAX));
        int i,j,k;
        for(i=1;i<=N;++i) dp[1][i]=i;
        for(;i<=K;++i){ // 从两个鸡蛋开始
            for(j=1;j<N;++j){
                for(k=2;k<N;++k){
                    dp[i][j]=min(dp[i][j], max(dp[i-1][k-1], dp[i][N-k]))+1; // 计算顺序有问题
                }
            }
        }
        return dp[K][N];
    }
};