// https://leetcode-cn.com/problems/repeated-substring-pattern/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i,j,k,size=s.size();
        bool jd;
        for(j=1;j<=(size/2);++j){
            if(size%j!=0) continue;
            // 判断长度为j是否满足条件
            jd=true;
            for(i=0;jd&&i<j;++i)
                for(k=i+j;k<size;k+=j)
                    if(s[i]!=s[k]) {jd=false; break;}
            if(jd) return true;
        }
        return false;
    }
};