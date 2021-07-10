// https://leetcode-cn.com/problems/display-table-of-food-orders-in-a-restaurant/
#include<bits/stdc++.h>
using namespace std;

struct struct_cmp{
    bool operator()(const string &a, const string &b) const{
        if(a.size()==b.size()) return a<b;
        return a.size()<b.size();
    }
};

class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<string, unordered_map<string, int>, struct_cmp> mp;
        set<string> st;
        for(auto &e:orders) {mp[e[1]][e[2]]++; st.insert(e[2]);}
        vector<vector<string>> ans;
        vector<string> titles;
        titles.push_back("Table");
        for(auto &p:st) titles.push_back(p);
        ans.push_back(titles);
        for(auto &p:mp){
            vector<string> t; t.push_back(p.first);
            for(auto &q:st) t.push_back(to_string(p.second[q]));
            ans.push_back(t);
        }
        return ans;
    }
};
