// https://leetcode-cn.com/problems/reverse-string-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    inline void jcalc(string& str, int i, int j){
        while(i<j) swap(str[i++], str[j--]);
    }
    string reverseStr(string s, int k) {
        int m=s.size(), i=0;
        while(i<m){
            if(i+2*k<=m) {
                jcalc(s, i, i+k-1);
                i=i+2*k;
            }else {
                jcalc(s, i, min(m-1, i+k-1));
                break;
            }
        }
        return s;
    }
};
