// https://leetcode-cn.com/problems/maximize-palindrome-length-from-subsequences/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        int i, j, diff, m=word1.size(), n=word2.size(), size=m+n, ans=0;
        string w=word1+word2;
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for(diff=0;diff<size;++diff){
            for(i=0;i<size-diff;++i){
                j=i+diff;
                if(i==j) dp[i][j]=1;
                else if(w[i]==w[j]) {
                    dp[i][j]=dp[i+1][j-1]+2;
                    if(i<m&&j>=m) ans=max(ans, dp[i][j]);
                }
                else dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                
            }
        }
        return ans;
    }
};