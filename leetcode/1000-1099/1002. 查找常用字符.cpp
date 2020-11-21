// https://leetcode-cn.com/problems/find-common-characters/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<char, int> jcount(string& s){
        map<char, int> mp;
        map<char, int>::iterator p;
        for(char c: s){
            if((p=mp.find(c))==mp.end()) mp[c]=1;
            else p->second++;
        }
        return mp;
    }
    void jmerge(map<char, int>& ans, map<char, int> add){
        map<char, int>::iterator p;
        // todo this is ok?
        for(p=ans.begin();p!=ans.end();p++) if(add.find(p->first)==add.end()) ans.erase(p);
        for(p=ans.begin();p!=ans.end();p++) p->second=min(p->second, add.find(p->first)->second);
    }
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        if(A.size()==0) return res;
        map<char, int> ans; // 统计字符出现的次数
        map<char, int>::iterator p;
        char c; bool f=true;
        for(auto s:A) if(f) ans=jcount(s), f=false; else jmerge(ans, jcount(s));
        for(p=ans.begin();p!=ans.end();p++) 
            while(p->second){
                res.push_back(string(1, p->first));
                p->second=p->second-1;
            }
        return res;
    }
};