// https://leetcode-cn.com/problems/generate-parentheses/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(int left, int right, int index, string& path, vector<string>& ans){
        if(index==path.size()) ans.push_back(path);
        if(left) {
            path[index]='(';
            jgo(left-1, right+1, index+1, path, ans);
        }
        if(right){
            path[index]=')';
            jgo(left, right-1, index+1, path, ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path(n*2,' ');
        jgo(n,0,0,path,ans);
        return ans;
    }
};