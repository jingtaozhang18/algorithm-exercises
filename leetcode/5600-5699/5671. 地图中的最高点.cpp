// https://leetcode-cn.com/contest/biweekly-contest-46/problems/map-of-highest-peak/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(), n=isWater[0].size(), i, j, k, x, y;
        queue<pair<int,int>> que;
        for(i=0;i<m;++i){
            for(j=0;j<n;++j){
                isWater[i][j]=1-isWater[i][j];
                if(isWater[i][j]==0) que.push(make_pair(i, j));
                else isWater[i][j]=INT_MAX;
            }
        }
        int dir[4][2]={0,1,0,-1,-1,0,1,0};
        while(!que.empty()){
            i=que.front().first, j=que.front().second;
            que.pop();
            for(k=0;k<4;++k){
                x=i+dir[k][0], y=j+dir[k][1];
                // cout<<x<<" "<<y<<endl;
                if(x>=0&&x<m&&y>=0&&y<n){
                    if(isWater[x][y]==INT_MAX) que.push(make_pair(x, y));
                    isWater[x][y]=min(isWater[x][y], isWater[i][j]+1);
                }
            }
        }
        return isWater;
    }
};