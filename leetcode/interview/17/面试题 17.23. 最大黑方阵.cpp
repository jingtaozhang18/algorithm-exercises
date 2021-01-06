// https://leetcode-cn.com/problems/max-black-square-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        vector<vector<int>> row(matrix); // 向右扩展的范围
        vector<vector<int>> col(matrix); // 向下扩展的范围
        int i, j, k, m=matrix.size(), n=matrix[0].size(), ans=0, ans_i, ans_j;
        for(i=0;i<m;++i) {
            row[i][n-1]=1-matrix[i][n-1];
            for(j=n-2;j>=0;--j) {
                if(!matrix[i][j]) row[i][j]=row[i][j+1]+1;
                else row[i][j]=0;
            }
        }
        for(i=0;i<n;++i){
            col[m-1][i]=1-matrix[m-1][i];
            for(j=m-2;j>=0;--j) {
                if(!matrix[j][i]) col[j][i]=col[j+1][i]+1;
                else col[j][i]=0;
            }
        }
        for(i=0;i<m;++i){
            for(j=0;j<n;++j) {
                for(k=min(row[i][j], col[i][j]);k>ans;--k){
                    if(row[i+k-1][j]>=k&&col[i][j+k-1]>=k) break;
                }
                if(k>ans) ans_i=i, ans_j=j, ans=k;
            }
        }
        return ans>0?vector<int>{ans_i, ans_j, ans}:vector<int>();
    }
};
