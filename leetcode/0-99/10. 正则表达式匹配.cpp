// https://leetcode-cn.com/problems/regular-expression-matching/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jgo(string&s, string&p, int i, int j){
        if(i==s.size()&&j==p.size()) return true;
        if(j==p.size()) return false; // 错误点: j结束了，但是i没有结束，匹配失败
        // 错误点，下面会出现i结束了，j还有的情况：为了应对j可以匹配0个元素的情况
        int k;
        if(j<p.size()-1&&p[j+1]=='*'){
            if(jgo(s,p,i,j+2)) return true; // 零个元素
            for(k=i;k<s.size()&&(s[k]==p[j]||p[j]=='.');++k){
                if(jgo(s, p, k+1, j+2)) return true;
            }
        }else{
            if(i==s.size()) return false; // 错误点：i结束了
            if(s[i]==p[j]||p[j]=='.') return jgo(s, p, i+1, j+1);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return jgo(s, p, 0, 0);
    }
};