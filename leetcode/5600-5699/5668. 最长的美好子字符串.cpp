// https://leetcode-cn.com/contest/biweekly-contest-46/problems/longest-nice-substring/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char jgo(char c){
        int diff='a'-'A';
        if(c>='a'&&c<='z') return c-diff;
        else return c+diff;
    }
    string longestNiceSubstring(string s) {
        int i, j, k,size=s.size();
        char x, y, z;
        int ans_i=0, ans=0;
        unordered_set<char> sta;
        unordered_set<char> stb;
        for(i=0;i<size;++i){
            for(j=size-1;j>i;--j){
                sta.clear();
                stb.clear();
                for(k=i;k<=j;++k){
                    x=s[k], y=jgo(x);
                    z=min(x, y);
                    // cout<<x<<" "<<y<<endl;
                    if(sta.find(z)==sta.end()){ // 不安全
                        if(stb.find(y)==stb.end()) stb.insert(x);
                        else{
                            sta.insert(z);
                            stb.erase(y);
                        }
                    }
                }
                if(stb.size()==0){
                    // cout<<i<<" "<<j<<endl;
                    if(j-i+1>ans) ans_i=i, ans=j-i+1;
                    break;
                }
            }
        }
        return s.substr(ans_i, ans);
    }
};