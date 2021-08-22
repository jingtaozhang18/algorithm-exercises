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

// 复习
class Solution {
public:
    void jgo(string& s, int index, vector<string>& ans){
        if(index==s.size()){
            ans.push_back(s);
            return;
        }
        unordered_set<char> st;
        for(int i=index;i<s.size();++i){
            if(st.find(s[i])!=st.end()){
                continue;
            }
            swap(s[i], s[index]);
            jgo(s, index+1, ans);
            swap(s[i], s[index]);
            st.insert(s[i]);
        }
    }
    vector<string> permutation(string s) {
        vector<string> ans;
        jgo(s, 0, ans);
        return ans;
    }
};
