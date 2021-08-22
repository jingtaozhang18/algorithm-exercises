// https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool match(string& s, string& p, int i, int j){
        if(i==s.size()&&j==p.size()) return true;
        if(j<p.size()-1&&p[j+1]=='*'){
            if(match(s,p,i,j+2)) return true; // 重复0次
            for(int x=i;x<s.size()&&(s[x]==p[j]||p[j]=='.');++x) // 重复1+次
                if(match(s,p,x+1,j+2)) return true;
        }
        if(i==s.size()||j==p.size()) return false;
        if(s[i]==p[j]||p[j]=='.') return match(s,p,i+1,j+1);
        return false;
    }
    bool isMatch(string s, string p) {
        return match(s,p,0,0);
    }
};

// 复习 自底向上
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size(), i, j;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        for(j=n-1;j>0;j-=2){ // 处理边界
            if(p[j]=='*') dp[m][j]=dp[m][j-1]=true; // p可以被截断
            else break;
        }
        dp[m][n]=true;
        for(j=n-1;j>=0;--j){ // p
            for(i=m-1;i>=0;--i){ // s
                if(p[j]!='*') dp[i][j]=dp[i][j]|((s[i]==p[j]||p[j]=='.')&dp[i+1][j+1]);
                else{
                    dp[i][j]=dp[i][j]||dp[i][j+1]; // 匹配0个
                    if(s[i]==p[j-1]||p[j-1]=='.') dp[i][j]=dp[i][j]||dp[i+1][j]; // 匹配1+个  dp[i+1][j]匹配了0+个
                    dp[i][j-1]=dp[i][j];
                }
            }
            if(p[j]=='*') --j;
        }
        return dp[0][0];
    }
};