// https://leetcode-cn.com/problems/ones-and-zeroes/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size, a, b, ans=0, i, j, k, valh, valn; // a,m: 0; b,n:1
        vector<pair<int, int>> arr;
        for(auto &s:strs){
            a=b=0;
            for(auto &c:s) if(c=='0') a++; else b++;
            if(a<=m&&b<=n) arr.push_back(make_pair(a, b));
        }
        size=arr.size();
        int dp[size+1][m+1][n+1];
        for(i=0;i<=size;++i) for(j=0;j<=m;++j) for(k=0;k<=n;++k) dp[i][j][k]=0;
        for(i=1;i<=size;++i){
            for(j=0;j<=m;++j){
                for(k=0;k<=n;++k){ // 考虑前i个物品在价格不超过j,k时背包的最大价值
                    if(j-arr[i-1].first>=0&&k-arr[i-1].second>=0) valh=dp[i-1][j-arr[i-1].first][k-arr[i-1].second];
                    else valh=0;
                    valn=dp[i-1][j][k];
                    dp[i][j][k]=max(valh+((j>=arr[i-1].first&&k>=arr[i-1].second)?1:0), valn);
                }
            }
        }
        return dp[size][m][n];
    }
};