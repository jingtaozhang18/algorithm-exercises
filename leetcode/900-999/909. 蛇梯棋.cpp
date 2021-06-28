// https://leetcode-cn.com/problems/snakes-and-ladders/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int m=board.size();
        int deep[m*m+1];
        queue<int> que;
        int i, t, x, a, b;
        for(i=2;i<=m*m;++i) deep[i]=INT_MAX;
        deep[1]=0; que.push(1);
        while(que.size()){
            t=que.front(); que.pop();
            for(i=t+1;i<=min(m*m, t+6);++i){ // 遍历其可以走过的路径
                a=m-1-(i-1)/m, b=((i-1)/m)%2==0?(i-1)%m:m-1-(i-1)%m, x=i;
                if(board[a][b]!=-1) x=board[a][b];
                if(deep[x]>deep[t]+1){
                    que.push(x);
                    deep[x]=deep[t]+1;
                }
            }
        }
        return deep[m*m]==INT_MAX?-1:deep[m*m];
    }
};
