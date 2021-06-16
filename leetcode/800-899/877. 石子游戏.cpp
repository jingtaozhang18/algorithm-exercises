// https://leetcode-cn.com/problems/stone-game/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int m=piles.size(), acc=0, i, j, k;
        int dp[m][m];
        for(auto &e:piles) acc+=e;
        for(i=0;i<m;++i) for(j=0;j<m;++j) dp[i][j]=0;
        for(k=0;k<m;++k){
            for(i=0;i<m-k;++i){
                j=i+k;
                if(!k) dp[i][j]=piles[i];
                else dp[i][j]=max(piles[i]+dp[i+1][j], piles[j]+dp[i][j-1]);
            }
        }
        return dp[0][m-1]*2>acc;
    }
};