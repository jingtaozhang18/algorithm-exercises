// https://leetcode-cn.com/problems/zuo-xuan-zhuan-zi-fu-chuan-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(string& s, int i, int j){
        char c;
        while(i<j) c=s[i],s[i]=s[j],s[j]=c,i++,--j;
    }
    string reverseLeftWords(string s, int n) {
        jgo(s, 0, n-1);
        jgo(s, n, s.size()-1);
        jgo(s, 0, s.size()-1);
        return s;
    }
};