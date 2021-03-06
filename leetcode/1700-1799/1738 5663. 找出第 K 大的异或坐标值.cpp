// https://leetcode-cn.com/problems/find-kth-largest-xor-coordinate-value/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<int>> que;
        int i,j, t, m=matrix.size(), n=matrix[0].size();
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(i>0) matrix[i][j]^=matrix[i-1][j];
            }
        }
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(j>0) matrix[i][j]^=matrix[i][j-1];
                que.push(matrix[i][j]);
                if(que.size()>k) que.pop();
            }
        }
        return que.top();
    }
};

// 每日一题
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int i, j, m=matrix.size(), n=matrix[0].size();
        priority_queue<int, vector<int>, greater<int>> que;
        for(i=1;i<m;++i){
            for(j=0;j<n;++j){
                matrix[i][j]^=matrix[i-1][j];
            }
        }
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                if(j>0) matrix[i][j]^=matrix[i][j-1];
                if(que.size()<k||matrix[i][j]>que.top()) que.push(matrix[i][j]);
                if(que.size()>k) que.pop();
            }
        }
        return que.top();
    }
};