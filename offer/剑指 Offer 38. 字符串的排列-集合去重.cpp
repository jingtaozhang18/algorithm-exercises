// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(string& s, int i, vector<string>& ans){
        if(i==s.size()) ans.push_back(s);
        char t;
        set<char> jset;
        for(int j=i;j<s.size();++j){
            if(jset.find(s[j])!=jset.end()) continue;
            jset.insert(s[j]);
            t=s[i],s[i]=s[j],s[j]=t;
            jgo(s,i+1,ans);
            t=s[i],s[i]=s[j],s[j]=t;
        }
    }
    vector<string> permutation(string s) {
        vector<string> ans;
        jgo(s, 0, ans);
        return ans;
    }
};