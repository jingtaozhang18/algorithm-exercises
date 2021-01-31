// https://leetcode-cn.com/contest/weekly-contest-226/problems/palindrome-partitioning-iv/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPartitioning(string s) {
        int size=s.size(), i, j, diff;
        vector<vector<bool>> dp(size, vector<bool>(size, false));
        for(diff=0;diff<size;++diff){
            for(i=0;i<size-diff;++i){
                j=i+diff;
                if(diff==0) dp[i][j]=true;
                else if(diff==1){
                    if(s[i]==s[j]) dp[i][j]=true;
                }else{
                    if(s[i]==s[j]&&dp[i+1][j-1]) dp[i][j]=true;
                }
            }
        }
        for(i=0;i<size-2;++i){
            if(dp[0][i])
                for(j=i+1;j<size-1;++j){
                    if(dp[i+1][j]&&dp[j+1][size-1]) return true;
                }
        }
        return false;
    }
};