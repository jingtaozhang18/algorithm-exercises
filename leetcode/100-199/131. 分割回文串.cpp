// https://leetcode-cn.com/problems/palindrome-partitioning/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jgo(string&s, int index, vector<vector<bool>>& dp, vector<string>& path, vector<vector<string>>& ans){
        if(index==s.size()) ans.push_back(path);
        for(int i=index;i<s.size();++i){
            if(dp[index][i]){
                path.push_back(s.substr(index, i-index+1));
                jgo(s, i+1, dp, path, ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int i,j,diff,k,size=s.size(),index;
        vector<vector<bool>> dp(size, vector<bool>(size, true));
        for(diff=1;diff<size;++diff){
            for(i=0;i<size-diff;++i){
                j=i+diff;
                dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];
            }
        }
        vector<string> path;
        jgo(s,0,dp,path,ans);
        return ans;
    }
};