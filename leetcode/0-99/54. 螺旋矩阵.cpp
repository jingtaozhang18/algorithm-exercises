// https://leetcode-cn.com/problems/spiral-matrix/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        if(!matrix.size()||!matrix[0].size()) return vector<int>();
        int a=0,b=0,c=matrix.size(),d=matrix[0].size(),i,k=0;
        vector<int> ans(c*d);
        --c,--d;
        while(a<=c&&b<=d){ // 上横不到头，右竖要到头，是所有矩阵都有的特点
            for(i=b;i<d;++i) ans[k++]=matrix[a][i];
            for(i=a;i<=c;++i) ans[k++]=matrix[i][d];
            if(a!=c&&b!=d) for(i=d-1;i>=b;--i) ans[k++]=matrix[c][i]; // 不是一条线
            if(a!=c&&b!=d) for(i=c-1;i>a;--i) ans[k++]=matrix[i][b];
            a++,b++,c--,d--;
        }
        return ans;
    }
};