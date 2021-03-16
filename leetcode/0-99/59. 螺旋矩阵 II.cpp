// https://leetcode-cn.com/problems/spiral-matrix-ii/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int up=0, down=n-1, left=0, right=n-1, i, j, k=1;
        while(up<=down&&left<=right){
            for(i=up, j=left; j<=right; ++j) ans[i][j]=k++;
            up++;
            if(up<=down&&left<=right){
                for(i=up, j=right; i<=down; ++i) ans[i][j]=k++;
            }
            right--;
            if(up<=down&&left<=right){
                for(i=down, j=right; j>=left; --j) ans[i][j]=k++;
            }
            down--;
            if(up<=down&&left<=right){
                for(i=down, j=left; i>=up; --i) ans[i][j]=k++;
            }
            left++;
        }
        return ans;
    }
};