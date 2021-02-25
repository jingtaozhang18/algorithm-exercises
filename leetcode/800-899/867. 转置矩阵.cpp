// https://leetcode-cn.com/problems/transpose-matrix/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int i, j, m=matrix.size(), n=matrix[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                ans[j][i]=matrix[i][j];
            }
        }
        return ans;
    }
};