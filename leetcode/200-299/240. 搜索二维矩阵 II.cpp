// https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size(), i=0, j=n-1;
        while(i<m&&j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) --j;
            else ++i;
        }
        return false;
    }
};