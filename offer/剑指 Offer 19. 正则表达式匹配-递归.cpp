// https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool match(string& s, string& p, int i, int j){
        if(i==s.size()&&j==p.size()) return true;
        if(j<p.size()-1&&p[j+1]=='*'){
            if(match(s,p,i,j+2)) return true; // 重复0次
            for(int x=i;x<s.size()&&(s[x]==p[j]||p[j]=='.');++x) // 重复1+次
                if(match(s,p,x+1,j+2)) return true;
        }
        if(i==s.size()||j==p.size()) return false;
        if(s[i]==p[j]||p[j]=='.') return match(s,p,i+1,j+1);
        return false;
    }
    bool isMatch(string s, string p) {
        return match(s,p,0,0);
    }
};