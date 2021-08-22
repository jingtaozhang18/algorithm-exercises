// https://leetcode-cn.com/problems/di-yi-ge-zhi-chu-xian-yi-ci-de-zi-fu-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        vector<int> mem(200,-1); // -1 没有出现, 0出现了一次, 1出现了多次
        int i;
        for(i=0;i<s.size();++i) if(mem[s[i]]<=0) mem[s[i]]++;
        for(i=0;i<s.size();++i) if(!mem[s[i]]) return s[i];
        return ' ';
    }
};