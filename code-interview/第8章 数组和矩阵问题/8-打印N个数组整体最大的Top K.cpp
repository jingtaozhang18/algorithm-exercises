#include<bits/stdc++.h>
using namespace std;

int main(void){
  priority_queue<int, vector<int>, greater<int> > que; // 最小堆 greater 从小到大的插入
  // priority_queue<int, vector<int>, less<int>>s; // 最大堆 less 从大到小的插入
  stack<int> sta;
  int n,k,m,i,t;
  scanf("%d%d", &n, &k);
  while(n--){
    scanf("%d",&m);
    while(m--) {
      scanf("%d", &t);
      if(que.size()<k) 
        que.push(t); 
      else {
        if(t>que.top()){
          que.pop();
          que.push(t);
        }
      }
    }
  }
  while(!que.empty()){
    sta.push(que.top());
    que.pop();
  }
  while(!sta.empty()){
    printf("%d ", sta.top());
    sta.pop();
  }
  return 0;
}