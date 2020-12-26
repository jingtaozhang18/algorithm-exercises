// https://leetcode-cn.com/problems/wildcard-matching/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jgo(string &s, string &p, int si, int pi){
        if(pi==p.size()){
            if(si==s.size()) return true;
            else return false;
        }
        // si仍有可能已经结束了
        if(p[pi]=='*'){
            // 优化点：多个紧挨在一起的*等于一个*
            do{pi++;}while(pi<p.size()&&p[pi]=='*');
            for(;si<=s.size();++si) // 错误点，此处可以全量匹配，因此是<=
                if(jgo(s, p, si, pi)) return true;
        }else{
            if(si==s.size()) return false;
            if(p[pi]=='?'||s[si]==p[pi])
            return jgo(s,p,si+1,pi+1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return jgo(s, p, 0, 0);
    }
};