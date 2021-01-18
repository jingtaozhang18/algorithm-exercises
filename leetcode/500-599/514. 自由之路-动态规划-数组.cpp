// https://leetcode-cn.com/problems/freedom-trail/
#include<bits/stdc++.h>
using namespace std;

// 包含不必要的计算
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        // 记录字符出现的所有位置
        unordered_map<char, vector<int>> mp;
        int i, j, size=ring.size(),n=key.size();
        for(i=0;i<size;++i) mp[ring[i]].push_back(i);
        vector<vector<int>> dp(size, vector<int>(n+1, 0));
        for(i=n-1;i>=0;--i){ // key[i:] 最少步骤
            for(j=0;j<size;++j){ // 从ring的第j个位置出发
                dp[j][i]=INT_MAX;
                for(auto e:mp[key[i]]){
                    dp[j][i]=min(dp[j][i], dp[e][i+1]+min(abs(e-j),size-abs(e-j)));
                }
            }
        }
        return dp[0][0]+n;
    }
};