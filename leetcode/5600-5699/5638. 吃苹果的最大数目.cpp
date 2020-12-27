// https://leetcode-cn.com/problems/maximum-number-of-eaten-apples/
#include<bits/stdc++.h>
using namespace std;

struct node{
  int date; // 保质期最后一天
  int num; // 数量
  node(int d, int n):date(d),num(n){}
  bool operator<(const node& other) const{
    return date>other.date;
  }
};
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
      int i, size=apples.size(), ans=0;
      priority_queue<node, vector<node>> que;
      for(i=0;i<size||!que.empty();++i){
        if(i<size&&apples[i]) que.push(node(i+days[i]-1, apples[i]));
        while(!que.empty()&&i>que.top().date) que.pop(); // 删除烂果
        if(!que.empty()&&que.top().num>0) {
          // cout<<i<<" "<<que.top().date<<endl;
          ++ans;
          if(que.top().num==1) que.pop();
          else{
            node t=que.top(); que.pop();
            t.num--; que.push(t);
          }
        }
      }
      return ans;
    }
};