// https://leetcode-cn.com/problems/set-matrix-zeroes/
#include<bits/stdc++.h>
using namespace std;

// O(1)的空间复杂度，先根据第一行第一列的数据判断第一行第一列是否需要置0，但是不修改原数组的值
// 然后利用第一行第一列去记录[1:][1:]部分是否需要置0
// 根据第一行第一列去修改[1:][1:]部分
// 根据第一步的结果，处理第一行第一列的效果
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int i, j, m=matrix.size(), n=matrix[0].size();
        bool up=false, left=false;
        for(j=0;j<n;++j) if(matrix[0][j]==0) break;
        if(j<n) up=true;
        for(i=0;i<m;++i) if(matrix[i][0]==0) break;
        if(i<m) left=true;
        for(i=1;i<m;++i){
            for(j=1;j<n&&matrix[i][j]!=0;++j);
            if(j<n) matrix[i][0]=0;
        }
        for(j=1;j<n;++j){
            for(i=1;i<m&&matrix[i][j]!=0;++i);
            if(i<m) matrix[0][j]=0;
        }
        for(i=1;i<m;++i){
            if(matrix[i][0]==0)
                for(j=1;j<n;++j) matrix[i][j]=0;
        }
        for(j=1;j<n;++j){
            if(matrix[0][j]==0)
                for(i=1;i<m;++i) matrix[i][j]=0;
        }
        if(up) for(j=0;j<n;++j) matrix[0][j]=0;
        if(left) for(i=0;i<m;++i) matrix[i][0]=0;
    }
};