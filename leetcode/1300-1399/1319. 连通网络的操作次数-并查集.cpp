// https://leetcode-cn.com/problems/number-of-operations-to-make-network-connected/
#include<bits/stdc++.h>
using namespace std;

struct jun{
    vector<int> mem;
    int size;
    jun(int n):mem(vector<int>(n)),size(n){for(int i=0;i<n;++i)mem[i]=i;};
    int find(int i){
        if(mem[i]!=i) mem[i]=find(mem[i]);
        return mem[i];
    }
    void merge(int i, int j){
        i=find(i), j=find(j);
        if(i!=j) mem[i]=j, size--;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        jun ju(n);
        for(auto e:connections) ju.merge(e[0],e[1]);
        return ju.size-1;
    }
};