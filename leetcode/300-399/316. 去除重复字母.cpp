// https://leetcode-cn.com/problems/remove-duplicate-letters/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char, int> mp;
        set<char> st;
        map<char, int>::iterator p;
        int i, j, size=s.size();
        for(i=0;i<size;++i) { // 统计char出现的次数
            p=mp.find(s[i]);
            if(p==mp.end()) mp[s[i]]=1;
            else p->second=p->second+1;
        }
        stack<char> sta; stack<char> tsta;
        for(i=0;i<size;++i){
            if(st.find(s[i])!=st.end()) {mp[s[i]]--; continue;}
            while(!sta.empty()&&mp[sta.top()]>1&&sta.top()>s[i]){
                mp[sta.top()]--;
                st.erase(st.find(sta.top()));
                sta.pop();
            }
            sta.push(s[i]), st.insert(s[i]);
        }
        string ans="";
        while(!sta.empty()){tsta.push(sta.top()); sta.pop();}
        while(!tsta.empty()){ans+=tsta.top(); tsta.pop();}
        return ans;
    }
};