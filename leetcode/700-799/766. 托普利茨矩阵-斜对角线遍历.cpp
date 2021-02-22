// https://leetcode-cn.com/problems/toeplitz-matrix/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size(), i, j, diff, k;
        for(diff=-m+1;diff<=n-1;++diff){
            if(diff<0) i=-diff;
            else i=0;
            k=matrix[i][i+diff];
            for(;i+diff<n&&i<m;++i){
                if(matrix[i][i+diff]!=k) return false;
            }
        }
        return true;
    }
};