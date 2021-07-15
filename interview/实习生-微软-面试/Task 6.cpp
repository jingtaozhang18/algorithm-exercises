// A - B
// C - D
// E - F
// B - D

// 1. A - B - C - D
// 2. E - F
#include<bits/stdc++.h>
using namespace std;

class unionStruct{
    vector<int> mem;
    union(int n){
        mem=vector<int>(n);
        for(int i=0;i<n;++i) mem[i]=i;
    }
    int find(int i){
        if(mem[i]==i) return i;
        return mem[i]=find(mem[mem[i]]);
    }
    void union(int i, int j){
        i=find(i);
        j=find(j);
        if(i!=j) mem[i]=j;
    }
};

vector<vector<int>> calc(vector<pair<int, int>>& input){
    unordered_set<int> st;
    unordered_map<int, int> mp;
    int i, n=input.size(), m;
    for(i=0;i<n;++i){
        st.insert(input[i].first);
        st.insert(input[i].second);
    }
    m=st.size();
    for(auto p=st.begin(), i=0; p!=st.end(); ++p, ++i){
        mp[p]=i;
    }
    unionStruct un(m);
    for(i=0;i<n;++i){
        un.union(mp[input[i].first], mp[input[i].second]);
    }
    unordered_map<int, vector<int>> ret;
    for(auto p=st.begin(); p!=st.end(); ++p){
        ret[un.find(mp[p])].push_back(p);
    }
    vector<vector<int>> ans;
    for(auto p=ret.begin(); p!=ret.end(); ++p){
        ans.push_back(p.second);
    }
    return ans;
}