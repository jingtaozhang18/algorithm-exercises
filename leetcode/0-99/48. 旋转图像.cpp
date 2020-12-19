// https://leetcode-cn.com/problems/rotate-image/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i, j, size=matrix.size(), t;
        for(i=0;i<=(size>>1);++i){
            for(j=i;j<size-i-1;++j){
                t=matrix[i][j];
                matrix[i][j]=matrix[size-1-j][i]; // 左上角向右
                matrix[size-1-j][i]=matrix[size-1-i][size-j-1]; // 左下角向上
                matrix[size-1-i][size-j-1]=matrix[j][size-1-i]; // 右下角向左
                matrix[j][size-1-i]=t; // 右上角向下
            }
        }
    }
};