// https://leetcode-cn.com/problems/network-delay-time/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int arr[n+1], i, j, x, ans=0;
        unordered_map<int, vector<pair<int,int>>> mp;
        queue<int> que;
        for(i=0;i<=n;++i) arr[i]=INT_MAX;
        for(auto &e:times) mp[e[0]].push_back(make_pair(e[1], e[2]));
        arr[k]=0;
        que.push(k);
        while(que.size()){
            x=que.front();
            que.pop();
            for(auto &e:mp[x]){
                if(arr[e.first]>arr[x]+e.second){
                    que.push(e.first);
                    arr[e.first]=e.second+arr[x];
                }
            }
        }
        for(i=1;i<=n;++i){
            ans=max(ans, arr[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};
