// https://leetcode-cn.com/problems/count-submatrices-with-all-ones/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int> >& mat) {
        int ans=0, i, j, k, x, m=mat.size(), n=mat[0].size();
        stack<int> sta;
        vector<int> mright(n);
        for(i=0;i<m;++i){
            for(j=0;j<n;++j) mright[j]=n;
            while(sta.size()) sta.pop();
            if(i) for(j=0;j<n;++j) if(mat[i][j]) mat[i][j]+=mat[i-1][j];
            for(j=0;j<n;++j){
                while(sta.size()&&mat[i][sta.top()]>mat[i][j]){
                    mright[sta.top()]=j;
                    sta.pop();
                }
                sta.push(j);
            }
            for(j=0;j<n;++j){
                x=mright[j]; // 当前最右边界
                for(k=mat[i][j];k>0;--k){
                    while(x!=n&&mat[i][x]>=k) x=mright[x];
                    ans+=x-j;
                }
            }
        }
        return ans;
    }
};