// https://leetcode-cn.com/contest/weekly-contest-232/problems/check-if-one-string-swap-can-make-strings-equal/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i, j, m=s1.size(), n=s2.size();
        int a, b, diff=0;
        for(i=0;i<m;++i){
            if(s1[i]!=s2[i]){
                diff++;
                if(diff==1) a=i;
                else if(diff==2) b=i;
                else return false;
            }
        }
        if(diff==0) return true;
        if(diff==1) return false;
        if(s1[a]==s2[b]&&s1[b]==s2[a]) return true;
        return false;
    }
};