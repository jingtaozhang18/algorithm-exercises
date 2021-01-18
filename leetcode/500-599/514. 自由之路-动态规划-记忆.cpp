// https://leetcode-cn.com/problems/freedom-trail/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> dp;
    int jgo(unordered_map<char, vector<int>>& mem, int now, int i, string &key, int size){
        // 从now位置打印出i及i位置之后字符串需要的最少步骤
        if(i==key.size()) return 0;
        // 从函数中发现函数的状态只和now以及i相关，属于独立的子问题，添加记忆，避免重复计算
        int sk=now*key.size()+i;
        if(dp.find(sk)!=dp.end()) return dp[sk];
        int t=INT_MAX,a;
        // 暴力穷举
        for(auto e:mem[key[i]]){
            // 从now到e需要的旋转次数
            // a=min(max(now,e)-min(now,e), min(now,e)+size-max(now,e));
            a=min(abs(now-e), size-abs(now-e));
            // cout<<now<<" "<<e<<" "<<a<<endl;
            t=min(t, jgo(mem, e, i+1, key, size)+a);
        }
        return dp[sk]=t;
    }
    int findRotateSteps(string ring, string key) {
        // 记录字符出现的所有位置
        unordered_map<char, vector<int>> mp;
        int i, size=ring.size();
        for(i=0;i<size;++i) mp[ring[i]].push_back(i);
        return jgo(mp, 0, 0, key, size)+key.size();
    }
};