// https://leetcode-cn.com/problems/truncate-sentence/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string truncateSentence(string s, int k) {
        int i, j=0, n=s.size();
        for(i=0;i<n;++i){
            if(s[i]==' ') j++;
            if(j==k) break;
        }
        return s.substr(0, i);
    }
};