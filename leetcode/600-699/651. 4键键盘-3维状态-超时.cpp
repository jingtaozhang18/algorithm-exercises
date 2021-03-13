// https://leetcode-cn.com/problems/4-keys-keyboard/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, int> mem; //记忆
    int jgo(int n, int s, int c){ // 剩余次数，屏幕上的数量，粘贴板上的数量
        if(n<=0) return s;
        string key=to_string(n)+","+to_string(s)+","+to_string(c);
        if(mem.find(key)!=mem.end()) return mem[key];
        int ans=0;
        ans=max(ans, jgo(n-1, s+1, c));
        ans=max(ans, jgo(n-1, s+c, c));
        if(n>1) ans=max(ans, jgo(n-2, s, s));
        return mem[key]=ans;
    }
    int maxA(int n) {
        return jgo(n, 0, 0);
    }
};