// https://leetcode-cn.com/problems/palindromic-substrings/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int m=s.size(), i, j, k, ans=0;
        bool dp[m][m];
        for(i=0;i<m;++i) for(j=0;j<m;++j) dp[i][j]=(i==j);
        for(k=1;k<m;++k){
            for(i=0;i<m-k;++i){
                j=i+k;
                if((k==1||dp[i+1][j-1])&&s[i]==s[j]) {
                    ++ans;
                    dp[i][j]=true;
                }
            }
        }
        return ans+m;
    }
};