// https://leetcode-cn.com/problems/longest-word-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 和17.13相同的记忆思路
    bool mem[1002];
    bool jgo(string&str, int i, unordered_set<string> &st){
        if(i==str.size()) return true;
        if(mem[i]) return false;
        mem[i]=true;
        for(int j=i;j<str.size();++j){
            if(st.count(str.substr(i,j-i+1))){
                if(jgo(str, j+1, st)) return true;
            }
        }
        return false;
    }
    string longestWord(vector<string>& words) {
        auto cmp = [](string &a, string &b){
            if(a.size()==b.size()){
                return a<b;
            }else{
                return a.size()>b.size();
            }
        };
        sort(words.begin(), words.end(), cmp);
        unordered_set<string> st(words.rbegin(), words.rend());
        int i, j, n=words.size();
        for(i=0;i<n;++i){
            for(j=0;j<words[i].size();++j) mem[j]=false;
            st.erase(st.find(words[i]));
            if(jgo(words[i], 0, st)) return words[i];
            st.insert(words[i]);
        }
        return "";
    }
};