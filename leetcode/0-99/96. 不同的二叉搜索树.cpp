// https://leetcode-cn.com/problems/unique-binary-search-trees/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> mp;
    int numTrees(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        if(mp.find(n)!=mp.end()) return mp[n];
        int acc=0;
        for(int i=0;i<n;++i) acc+=numTrees(i)*numTrees(n-i-1);
        return mp[n]=acc;
    }
};