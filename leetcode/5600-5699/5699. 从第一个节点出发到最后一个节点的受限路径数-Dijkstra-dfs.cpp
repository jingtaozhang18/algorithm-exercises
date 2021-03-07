// https://leetcode-cn.com/problems/number-of-restricted-paths-from-first-to-last-node/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> mem;
    int mod=(1e9+7);
    int dfs(int i, vector<int>& distance, vector<vector<pair<int, int>>> & arr, int j){
        if(i==j) return 1;
        int ans=0;
        for(auto e:arr[i]){
            if(distance[e.first]<distance[i]){
                if(mem.find(e.first)==mem.end())
                    mem[e.first]=dfs(e.first, distance, arr, j);
                ans=(ans+mem[e.first])%mod;
            }
        }
        return ans;
    };
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> arr(n+1, vector<pair<int, int>>(0));
        int i, j, d;
        for(auto e:edges){
            arr[e[0]].push_back(make_pair(e[1], e[2]));
            arr[e[1]].push_back(make_pair(e[0], e[2]));
        }
        vector<int> distance(n+1, INT_MAX);
        distance[n]=0;
        auto cmp = [](pair<int, int> &a, pair<int, int>&b){return a.first>b.first;};
        // 从n出发
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
        que.push(make_pair(0, n));  // 
        while(que.size()){
            d=que.top().first, i=que.top().second;
            que.pop();
            for(auto e:arr[i]){
                if(distance[e.first]>d+e.second){ // 更新
                    distance[e.first]=d+e.second;
                    que.push(make_pair(distance[e.first], e.first));
                }
            }
        }
        // for(auto e:distance) cout<<e<<" ";
        // cout<<endl;
        // 从1开始遍历 dfs
        return dfs(1, distance, arr, n);
    
    }
};