// https://leetcode-cn.com/problems/finding-the-users-active-minutes/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp;
        unordered_map<int, int> tj;
        int i, j, n=logs.size();
        for(i=0;i<n;++i) mp[logs[i][0]].insert(logs[i][1]);
        for(auto p:mp){
            tj[p.second.size()]++;
        }
        vector<int> ans(k, 0);
        for(auto p:tj){
            ans[p.first-1]=p.second;
        }
        return ans;
    }
};