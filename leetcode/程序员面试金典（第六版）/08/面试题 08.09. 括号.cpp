// https://leetcode-cn.com/problems/bracket-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(int i, int left, int right, vector<string>& ans, string& path){
        if(i==path.size()) ans.push_back(path);
        if(left) {
            path[i]='(';
            jgo(i+1, left-1, right+1, ans, path);
        }
        if(right) {
            path[i]=')';
            jgo(i+1, left, right-1, ans, path);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path(2*n, ' ');
        jgo(0, n, 0, ans, path);
        return ans;
    }
};