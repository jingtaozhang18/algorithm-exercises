// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0) return false;
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size()&&j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) i++;
            else j--;
        }
        return false;
    }
};

// again
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=m?matrix[0].size():0, i=0, j=n-1;
        if(!m||!n) return false;
        while(i<m&&j>=0){
            if(matrix[i][j]==target) return true;
            if(matrix[i][j]>target) --j;
            else ++i;
        }
        return false;
    }
};