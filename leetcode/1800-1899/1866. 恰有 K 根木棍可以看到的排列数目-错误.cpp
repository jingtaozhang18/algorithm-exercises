// https://leetcode-cn.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, unsigned long long> mp;
    int mod=1e9+7;
    long long jgoC(int m, int n){ // m个数字里面取n个
        long long ans=1;
        int i;
        for(i=1;i<=n;++i) ans*=(m-i+1), ans/=i, ans%=mod;
        return ans;
    }
    long long jgoA(int m){
        long long ans=1;
        while(m) ans*=m, m--, ans%=mod;
        return ans;
    }
    int rearrangeSticks(int n, int k) {
        if(k==0) return 1;
        if(k==1) return jgoA(n-1);
        int key=n*2000+k;
        if(mp.find(key)!=mp.end()) return mp[key];
        int i;
        unsigned long long ans=0, x;
        for(i=k-1;i<n;++i){ // 最大的放在位置i上，前面有i个，后面有n-1-i个
            x=((jgoC(n-1, i)%mod) * rearrangeSticks(i, k-1)%mod)* (jgoA(n-1-i)%mod);
            ans+=x;
            ans%=mod;
        }
        return mp[key]=ans;
    }
};