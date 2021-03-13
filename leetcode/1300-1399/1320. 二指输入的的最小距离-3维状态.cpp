// https://leetcode-cn.com/problems/minimum-distance-to-type-a-word-using-two-fingers/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calc(int a, int b){
        int ax=a/6, ay=a%6, bx=b/6, by=b%6;
        int diff_a=ax-bx, diff_b=ay-by;
        if(diff_a<0) diff_a=-diff_a;
        if(diff_b<0) diff_b=-diff_b;
        return diff_a+diff_b;
    }
    int minimumDistance(string word) {
        int dp[301][26][26], i, j, k, v, n=word.size(), ans=INT_MAX; // dp[i][j][k] 第i-1个字符左手在j位置，右手在k位置时的最小移动距离
        for(i=0;i<=n;++i){
            for(j=0;j<26;++j){
                for(k=0;k<26;++k){
                    if(i==0) dp[i][j][k]=0;
                    else dp[i][j][k]=INT_MAX-20;
                }
            }
        }
        for(i=1;i<=n;++i){
            v = word[i-1]-'A';
            for(j=0;j<26;++j){
                for(k=0;k<26;++k){
                    dp[i][v][k] = min(dp[i][v][k], dp[i-1][j][k]+calc(j, v));
                    dp[i][j][v] = min(dp[i][j][v], dp[i-1][j][k]+calc(k, v));
                    if(i==n){
                        ans=min(ans, dp[i][v][k]);
                        ans=min(ans, dp[i][j][v]);
                    }
                }
            }
        }
        return ans;
    }
};
