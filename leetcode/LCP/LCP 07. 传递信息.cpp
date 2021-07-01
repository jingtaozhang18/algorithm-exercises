// https://leetcode-cn.com/problems/chuan-di-xin-xi/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        vector<int> dp(n,0); // 到该点的方法数
        vector<int> add(n,0); // 上一轮对下一轮的贡献
        int i,j;
        dp[0]=1;
        while(k--){
            for(i=0;i<relation.size();++i)
                add[relation[i][1]]+=dp[relation[i][0]];
            for(i=0;i<n;++i) dp[i]=add[i], add[i]=0;
        }
        return dp[n-1];
    }
};

// 复习，速度更快
class Solution {
public:
    int numWays(int n, vector<vector<int>>& relation, int k) {
        unordered_map<int, vector<int>> mp;
        for(auto&r:relation) mp[r[0]].push_back(r[1]);
        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0]=1;
        int i, j, a, b;
        for(i=0;i<k;++i){ // k轮传递
            a=i%2, b=(i+1)%2;
            for(j=0;j<n;++j) dp[b][j]=0;
            for(j=0;j<n;++j){
                if(dp[a][j]){ // 开始传递
                    for(auto &e:mp[j]){
                        dp[b][e]+=dp[a][j];
                    }
                }
            }
        }
        return dp[k%2][n-1];
    }
};