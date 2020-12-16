// https://leetcode-cn.com/problems/rank-transform-of-a-matrix/
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val, i, j, rank;
    node(){}
    node(int val, int i, int j):val(val),i(i),j(j),rank(0){}
    bool operator<(const node& other) const{
        // if(val==other.val) return rank>other.rank;
        return val<other.val;
    }
};

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int i,j,k,x,y,m=matrix.size(), n=matrix[0].size();
        node nd;
        vector<node> arr;
        for(i=0;i<m;++i) for(j=0;j<n;++j) arr.push_back(node(matrix[i][j],i,j));
        sort(arr.begin(), arr.end());
        vector<int> row_index(m,0), row_val(m,INT_MIN), col_index(n,0), col_val(n, INT_MIN);
        vector<vector<int>> ans(m, vector<int>(n));
        for(i=0;i<m*n;++i){
            nd=arr[i];
            arr[i].rank=max(row_index[nd.i], col_index[nd.j]);
            for(k=i,j=i+1;j<m*n&&arr[j].val==nd.val;++j) { // 相同的val，需要根据当前所在行列的最大rank进行排序
                arr[j].rank=max(row_index[arr[j].i], col_index[arr[j].j]);
                if(arr[j].rank>arr[k].rank) k=j;
            }
            nd=arr[k], arr[k]=arr[i], arr[i]=nd;
            x=row_index[nd.i], y=col_index[nd.j];
            if(nd.val>row_val[nd.i]) ++x, row_val[nd.i]=nd.val;
            if(nd.val>col_val[nd.j]) ++y, col_val[nd.j]=nd.val;
            x=max(x, y);
            ans[nd.i][nd.j]=x;
            row_index[nd.i]=col_index[nd.j]=x;
        }
        return ans;
    }
};