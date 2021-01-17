// https://leetcode-cn.com/contest/weekly-contest-224/problems/largest-submatrix-with-rearrangements/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int i,j,m=matrix.size(), n=matrix[0].size();
        for(j=0;j<n;++j){
            for(i=m-2;i>=0;--i){
                if(matrix[i][j]==1) matrix[i][j]=matrix[i+1][j]+1;
            }
        }
        for(i=0;i<m;++i){
            sort(matrix[i].rbegin(), matrix[i].rend());
        }
        int ans=0;
        for(i=0;i<m;++i){
            for(j=0;j<n&&matrix[i][j];++j){
                ans=max(ans, (j+1)*matrix[i][j]);
            }
        }
        return ans;
    }
};