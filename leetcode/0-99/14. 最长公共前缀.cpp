// https://leetcode-cn.com/problems/longest-common-prefix/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        int i=0,j;
        for(;i<strs[0].size();++i){
            for(j=1;j<strs.size();++j){
                if(i>=strs[j].size()||strs[j][i]!=strs[0][i]) break;
            }
            if(j<strs.size()) break;
        }
        return strs[0].substr(0,i);
    }
};