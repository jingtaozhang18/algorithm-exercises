// https://leetcode-cn.com/problems/smallest-string-with-swaps/
#include<bits/stdc++.h>
using namespace std;

struct junion{
    vector<int> mem;
    vector<int> weight;
    junion(int n):mem(n),weight(n, 1){
        for(int i=0;i<n;++i) mem[i]=i;
    }
    // int find(int i){
    //     while(mem[i]!=i){
    //         mem[i]=mem[mem[i]];
    //         i=mem[i];
    //     }
    //     return i;
    // }
    // 这两种究竟哪个快，貌似不太好说
    int find(int i){
        if(mem[i]!=i) mem[i]=find(mem[i]);
        return mem[i];
    }
    // void merge(int i, int j){
    //     i=find(i);
    //     j=find(j);
    //     if(i!=j) mem[i]=j;
    // }
    // 使用带权重的合并之后，速度没有明显的提升
    void merge(int i, int j){
        i=find(i);
        j=find(j);
        if(i!=j) {
            if(weight[i]>weight[j]) swap(i,j);
            mem[i]=j;
            weight[j]+=weight[i];
        }
    }
};
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int size=s.size(), i;
        junion ju(size);
        for(auto e:pairs) ju.merge(e[0], e[1]);
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> mp;
        for(i=0;i<size;++i) mp[ju.find(i)].push(s[i]);
        for(i=0;i<size;++i) {
            s[i]=mp[ju.find(i)].top();
            mp[ju.find(i)].pop();
        }
        return s;
    }
};
