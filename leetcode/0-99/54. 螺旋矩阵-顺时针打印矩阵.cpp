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

// 复习， 还是比较晕
// 剥洋葱的做法，每次去掉一条边，去掉之前需要保证矩形还存在，相比于上面的方法要更好理解一些
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=m?matrix[0].size():0;
        int up=0, down=m-1, left=0, right=n-1, i, j;
        vector<int> ans;
        while(up<=down&&left<=right){
        // 拿掉上边，上边界往下缩一下
        for(i=up,j=left;j<=right;++j)ans.push_back(matrix[i][j]);
        up++;
        // 若矩形还存在，拿掉右边，右边界往左缩一下
        if(left<=right&&up<=down) for(i=up, j=right;i<=down;++i)ans.push_back(matrix[i][j]);
        right--;
        // 若矩形还存在，拿掉下边，下边界往上缩一下
        if(up<=down&&left<=right) for(i=down,j=right;j>=left;--j)ans.push_back(matrix[i][j]);
        down--;
        // 若矩形还存在，拿掉左边，左边界往右缩一下
        if(up<=down&&left<=right) for(i=down,j=left;i>=up;--i)ans.push_back(matrix[i][j]);
        left++;
        }
        return ans;
    }
};