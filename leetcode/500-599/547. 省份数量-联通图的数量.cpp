// https://leetcode-cn.com/problems/number-of-provinces/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 联通图的数量
    int findCircleNum(vector<vector<int>>& isConnected) {
      int i,c,v,size=isConnected.size();
      int color=0;
      vector<int> record(size, 0);
      queue<int> que;
      for(i=0;i<size;++i){
        if(record[i]==0){
          // 开始探索 BFS 染色
          color++;
          que.push(i);
          record[i]=color;
          while(!que.empty()){
            c=que.front();
            que.pop();
            for(v=0;v<size;++v){
              if(record[v]==0&&isConnected[c][v]==1){
                record[v]=color;
                que.push(v);
              }
            }
          }
        }
      }
      return color;
    }
};