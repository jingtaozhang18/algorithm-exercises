// https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
public:
    vector<vector<int>> arr;
    NumMatrix(vector<vector<int>>& matrix) {
        int i, j, m=matrix.size(), n=(m!=0)?matrix[0].size():0; // 错误点： 考虑边界
        arr=vector<vector<int>>(m+1, vector<int>(n+1));
        for(i=1;i<=m;++i){
            for(j=1;j<=n;++j){
                arr[i][j]=arr[i-1][j]+matrix[i-1][j-1]; // 脑子是个好东西
            }
        }
        for(i=1;i<=m;++i){
            for(j=2;j<=n;++j){
                arr[i][j]+=arr[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=arr[row2+1][col2+1]; // 总面积大小
        sum-=arr[row1][col2+1];
        sum-=arr[row2+1][col1];
        sum+=arr[row1][col1];
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */