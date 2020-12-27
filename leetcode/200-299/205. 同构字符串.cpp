// https://leetcode-cn.com/problems/isomorphic-strings/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int m=s.size(), n=t.size(), i, j;
        if(m!=n) return false;
        unordered_map<char, char> mp; // 字符映射表
        unordered_map<char, char>::iterator p;
        set<char> st; // 映射过的字符
        for(i=0;i<m;++i){
            if(mp.find(s[i])!=mp.end()){ // 映射过
                if(mp[s[i]]!=t[i]) return false;
            }else{
                mp[s[i]]=t[i];
                if(st.find(t[i])!=st.end()) return false; // 保证映射的字符不重复
                st.insert(t[i]);
            }
        }
        return true;
    }
};