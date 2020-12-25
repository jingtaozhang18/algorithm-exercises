// https://leetcode-cn.com/problems/assign-cookies/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i, j, ans=0;
        for(j=0,i=0;i<s.size();++i){
            if(j==g.size()) break;
            if(s[i]>=g[j]) j++, ans++;
        }
        return ans;
    }
};