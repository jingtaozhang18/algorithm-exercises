// https://leetcode-cn.com/contest/weekly-contest-232/problems/find-center-of-star-graph/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        int a,b;
        for(auto e:edges){
            a=e[0],b=e[1];
            mp[a]++, mp[b]++;
            st.insert(a); st.insert(b);
        }
        for(auto p:mp){
            if(p.second==st.size()-1) return p.first;
        }
        return -1;
    }
};