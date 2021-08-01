// https://leetcode-cn.com/problems/the-k-weakest-rows-in-a-matrix/
#include<bits/stdc++.h>
using namespace std;

struct state{
    int row, val;
    bool operator<(const state&other) const{
        if(val==other.val) return row<other.row;
        return val<other.val;
    }
};
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<state> que;
        int i, j, x;
        state sta;
        for(i=0;i<mat.size();++i){
            for(j=x=0;j<mat[i].size()&&mat[i][j]==1;++j) x++;
            sta.row=i, sta.val=x;
            que.push(sta);
            if(que.size()>k) que.pop();
        }
        vector<int> ans(que.size());
        i=que.size()-1;
        while(que.size()) {
            ans[i--]=que.top().row; 
            que.pop();
        }
        return ans;
    }
};
