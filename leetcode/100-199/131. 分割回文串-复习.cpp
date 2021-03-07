// https://leetcode-cn.com/problems/palindrome-partitioning/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(vector<vector<bool>> &dp, string &s, int i, vector<string> & path, vector<vector<string>>& ans){
        if(i==s.size()) ans.push_back(path);
        path.push_back("");
        for(int j=i;j<s.size();++j){
            if(dp[i][j]){
                path[path.size()-1]=s.substr(i, j-i+1);
                jgo(dp, s, j+1, path, ans);
            }
        }
        path.pop_back();
    }
    vector<vector<string>> partition(string s) {
        int i, j, k, n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        for(k=1;k<n;++k){
            for(i=0;i<n-k;++i){
                j=i+k;
                dp[i][j]=dp[i+1][j-1]&s[i]==s[j];
            }
        }
        vector<vector<string>> ans;
        vector<string> path;
        jgo(dp, s, 0, path, ans);
        return ans;
    }
};