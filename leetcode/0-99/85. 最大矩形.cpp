// https://leetcode-cn.com/problems/maximal-rectangle/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return 0;
        int m=matrix.size(),n=matrix[0].size(),i,j,ans=0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(i==0){
                    if(matrix[i][j]=='1') dp[i][j]=1;
                }else{
                    if(matrix[i][j]=='1') dp[i][j]=dp[i-1][j]+1;
                }
            }
        }
        stack<int> sta;
        vector<int> left(n, -1);
        vector<int> right(n, n);
        for(j=m-1;j>=0;--j){
            sta=stack<int>();
            left=vector<int>(n, -1);
            right=vector<int>(n, n);
            for(i=0;i<n;++i){ // 单增栈
                while(!sta.empty()&&dp[j][i]<dp[j][sta.top()]){
                    right[sta.top()]=i; sta.pop();
                }
                left[i] = (sta.empty() ? -1 : sta.top());
                sta.push(i);
            }
            for(i=0;i<n;++i){
                ans=max((right[i]-left[i]-1)*dp[j][i], ans);
            }
        }
        return ans;
    }
};