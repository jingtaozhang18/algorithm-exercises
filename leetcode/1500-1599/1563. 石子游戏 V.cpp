// https://leetcode-cn.com/problems/stone-game-v/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size(), i, j, k, x, v,a,b;
        int dp[n][n];
        int acc[n+1];
        memset(dp, 0, sizeof(dp));
        acc[0]=0;
        for(i=0;i<n;++i) acc[i+1]=acc[i]+stoneValue[i];
        for(k=1;k<n;++k){
            for(i=0;i<n-k;++i){
                j=i+k, v=INT_MIN;
                for(x=i+1;x<=j;++x){
                    a=acc[x]-acc[i];
                    b=acc[j+1]-acc[x];
                    if(a>b) a=b+dp[x][j];
                    else if(a<b) a+=dp[i][x-1];
                    else a+=max(dp[x][j], dp[i][x-1]);
                    v=max(v, a);
                }
                dp[i][j]=v;
            }
        }
        return dp[0][n-1];
    }
};