// https://leetcode-cn.com/problems/redundant-connection/
#include<bits/stdc++.h>
using namespace std;

struct jun{
    vector<int> mem;
    jun(int n){
        mem=vector<int>(n);
        for(int i=0;i<n;++i) mem[i]=i;
    }
    int find(int i){
        if(mem[i]!=i) mem[i]=find(mem[i]);
        return mem[i];
    }
    void merge(int i, int j){
        i=find(i);
        j=find(j);
        if(i!=j) mem[i]=j;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size=edges.size();
        jun ju(size+1);
        for(auto e:edges){
            if(ju.find(e[0])==ju.find(e[1])) return e;
            ju.merge(e[0], e[1]);
        }
        return vector<int>();
    }
};