// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(string& s, int i, vector<string>& ans){
        if(i==s.size()) ans.push_back(s);
        bool arr[26]; for(int k=0;k<26;++k)arr[k]=false;
        char t;
        for(int j=i;j<s.size();++j){
            if(arr[s[j]-'a']) continue; arr[s[j]-'a']=true;
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
    void jgo(string &s, int i, vector<string> &ans){
        if(i==s.size()) ans.push_back(s);
        vector<bool> used(200, false);
        for(int j=i;j<s.size();++j){
            if(used[s[j]]==false){
                swap(s[i], s[j]);
                jgo(s, i+1, ans);
                swap(s[i], s[j]);
                used[s[j]]=true;
            }
        }
    }

    vector<string> permutation(string s) {
        vector<string> ans;
        jgo(s, 0, ans);
        return ans;
    }
};