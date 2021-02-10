// https://leetcode-cn.com/problems/unique-substrings-in-wraparound-string/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int right=0, size=p.size(), i, ans=0, cnt=0;
        unordered_map<char, int> map;
        for(right=0;right<size;++right){
            if(right==0||(p[right-1]-'a'+1)%26!=(p[right]-'a')) cnt=1;
            else cnt++;
            map[p[right]]=max(cnt, map[p[right]]);
        }
        for(auto p:map) ans+=p.second;
        return ans;
    }
};