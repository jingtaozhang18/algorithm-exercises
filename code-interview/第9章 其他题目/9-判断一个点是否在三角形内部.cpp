// https://www.nowcoder.com/practice/f9c4290baed0406cbbe2c23dd687732c?tpId=101&&tqId=33127&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include<bits/stdc++.h>
using namespace std;

void calc(double dx0, double dy0, double dx2, double dy2, double dx3, double dy3, double &a, double &b){
  a=(dy0-dx0*dy3/dx3)/(dy2-dx2*dy3/dx3);
  b=(dx0-a*dx2)/dx3;
}

int main(void){
  double x1,y1,x2,y2,x3,y3,x,y,a,b;
  cin>>x1>>y1>>x2>>y2>>x3>>y3>>x>>y;
  calc(x-x3,y-y3,x1-x3,y1-y3,x2-x3,y2-y3,a,b);
  if(0<a&&0<b){
    calc(x-x2,y-y2,x1-x2,y1-y2,x3-x2,y3-y2,a,b);
    if(0<a&&0<b) cout<<"Yes";
    else cout<<"No";
  }else{
    cout<<"No";
  }
  return 0;
}