// https://leetcode-cn.com/problems/find-the-difference/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mps, mpt;
        unordered_map<char, int>::iterator p;
        for(char c:s) mps[c]++;
        for(char c:t) mpt[c]++;
        for(p=mpt.begin();p!=mpt.end();++p){
            if(p->second>mps[p->first]) return p->first;
        }
        return ' ';
    }
};