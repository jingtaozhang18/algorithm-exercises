// https://leetcode-cn.com/problems/permutation-ii-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(vector<string>& ans, string &s, int index){
        if(index==s.size()) {ans.push_back(s); return;}
        unordered_set<char> st;
        for(int i=index;i<s.size();++i){
            if(st.count(s[i])) continue;
            st.insert(s[i]);
            swap(s[i], s[index]);
            jgo(ans, s, index+1);
            swap(s[i], s[index]);
        }
    }
    vector<string> permutation(string S) {
        vector<string> ans;
        jgo(ans, S, 0);
        return ans;
    }
};
