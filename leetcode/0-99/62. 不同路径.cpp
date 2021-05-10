// https://leetcode-cn.com/problems/unique-paths/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> arr(2, vector<int>(n, 0));
        int i, j;
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(i==0&&j==0) arr[i%2][j]=1; else arr[i%2][j]=0;
                if(i) arr[i%2][j]+=arr[(i+1)%2][j];
                if(j) arr[i%2][j]+=arr[i%2][j-1];
            }
        }
        return arr[(m+1)%2][n-1];
    }
};