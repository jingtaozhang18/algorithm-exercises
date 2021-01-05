//https://www.nowcoder.com/practice/4d76096de4754712aa6ebecd9737fcf5?tpId=101&&tqId=33121&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include<bits/stdc++.h>
using namespace std;

long long oil[100002];
long long dis[100002];
bool can[100002];
int main(void){
  int n,i,init=-1,start,end,step;
  long long need,rest;
  cin>>n;
  for(i=0;i<n;++i)cin>>oil[i];
  for(i=0;i<n;++i)cin>>dis[i];
  for(i=0;i<n;++i){
    oil[i]-=dis[i];
    if(oil[i]>=0) init=i; // 错误点：此处大于等于0就行，而不需要大于0
  }
  if (init==-1) {for(i=0;i<n;++i) cout<<0<<" "; return 0;}
  // 可能存在良好出发点
  start=init, end=(start+1)%n, need=0, rest=oil[init], step=1; // 错误点：step初始化已经走了一步了
  for(i=0;i<n;++i){ // 为了保证每个位置都被遍历到
    while(rest+oil[end]>=0&&step<n){ // 向后扩展,向后扩展的条件是加上下一个状态，净值大于等于0
      rest+=oil[end], end=(end+1)%n, step++;
    }
    if(step==n&&need==0) can[start]=true; // 当前位置没有欠债并且已经扩展到了整个区域
    start=start==0?n-1:start-1; // 回退到前一个点
    if(oil[start]>=need){
      rest+=(oil[start]-need), need=0; //把油料贯穿到队尾
    }else{
      need-=oil[start]; // 背负债务
    }
  }
  for(i=0;i<n;++i)cout<<(can[i]?1:0)<<" ";
  return 0;
}