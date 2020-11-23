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