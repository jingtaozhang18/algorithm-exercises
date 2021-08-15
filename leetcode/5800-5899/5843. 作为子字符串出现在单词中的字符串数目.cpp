// https://leetcode-cn.com/problems/number-of-strings-that-appear-as-substrings-in-word/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judge(string& a, string& b){ // a是否是b的子串
        if(a.size()>b.size()) return false;
        int i, j;
        for(i=0;i<=b.size()-a.size();++i){
            for(j=0;j<a.size();++j){
                if(a[j]!=b[i+j]) break;
            }
            if(j==a.size()) return true;
        }
        return false;
    }
    int numOfStrings(vector<string>& patterns, string word) {
        int ans=0;
        for(auto& str:patterns){
            if(judge(str, word)){
                ++ans;
            }
        }
        return ans;
    }
};