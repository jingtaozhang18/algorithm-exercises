// https://leetcode-cn.com/problems/super-egg-drop/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(int k, int n, unordered_map<int, int>& mp){
        if(k==1) return n;
        if(n==0) return 0;
        int key=k*10000+n;
        unordered_map<int, int>::iterator p=mp.find(key);
        if(p!=mp.end()) return p->second;
        int ans=INT_MAX;
        int l=1,r=n,c;
        while(l<=r){
            c=l+((r-l)>>1);
            int b=jgo(k-1, c-1, mp); // 增
            int nb=jgo(k, n-c, mp); // 减
            ans=min(ans, max(b,nb)+1);
            if(b<nb) l=c+1; else r=c-1;
        }
        mp[key]=ans;
        return ans;
    }
    int superEggDrop(int K, int N) {
        unordered_map<int, int> memo; // 错误点，map的速度 远不及unordered_map的速度
        return jgo(K, N, memo);
    }
};