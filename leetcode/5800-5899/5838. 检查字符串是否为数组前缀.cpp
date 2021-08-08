// https://leetcode-cn.com/contest/weekly-contest-253/problems/check-if-string-is-a-prefix-of-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i, j, k=0, m=words.size(), n=s.size();
        for(i=0;i<m;++i){
            if(words[i].size()>n-k) 
                return false;
            for(j=0;j<words[i].size();++j, ++k){
                if(words[i][j]!=s[k]) 
                    return false;
            }
            if(k==n) return true;
        }
        return false;
    }
};