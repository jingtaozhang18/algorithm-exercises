// https://leetcode-cn.com/problems/search-a-2d-matrix/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        int left=0, right=m*n-1, mid, i, j;
        while(left<=right){
            mid=(left+right)>>1;
            i = mid/n, j = mid%n;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) right=mid-1;
            else left=mid+1;
        }
        return false;
    }
};