// https://www.nowcoder.com/practice/6369cbb6898c41d0bef179a6a80f5fde?tpId=101&&tqId=33126&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
// 点到边的距离都小于边的长度
// 点在边上的投影都在边上
#include<bits/stdc++.h>
using namespace std;

int main(void){
  double x1,x2,x3,x4,y1,y2,y3,y4,x,y,a,b;
  cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>x>>y;
  double dy0=y-y1,dx0=x-x1,dx2=x2-x1,dy2=y2-y1,dx3=x3-x1,dy3=y3-y1;
  a=(dy0-dx0*dy3/dx3)/(dy2-dx2*dy3/dx3);
  b=(dx0-a*dx2)/dx3;
  if(0<a&&a<1&&0<b&&b<1)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}