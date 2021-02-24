// https://leetcode-cn.com/problems/flipping-an-image/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int i, j, k, m=A.size(), n=A[0].size();
        for(i=0;i<m;++i){
            for(j=0, k=n-1;j<k;++j,--k){
                swap(A[i][j], A[i][k]);
                A[i][j]=1-A[i][j], A[i][k]=1-A[i][k];
            }
            if(j==k) A[i][j]=1-A[i][j];
        }
        return A;
    }
};
