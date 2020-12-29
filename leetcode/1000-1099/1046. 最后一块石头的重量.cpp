// https://leetcode-cn.com/problems/last-stone-weight/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> que;
        for(int a:stones) que.push(a);
        int x,y;
        while(!que.empty()){
          y=que.top(); que.pop();
          if(que.empty()) return y;
          x=que.top(); que.pop();
          if(x==y) continue;
          else que.push(y-x);
        }
        return 0;
    }
};