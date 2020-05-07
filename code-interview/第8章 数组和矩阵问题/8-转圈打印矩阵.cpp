#include<bits/stdc++.h>
using namespace std;

int go[4][4]={ // i,j,n,m的变化
  0,1,0,-1, // 向右
  1,0,-1,0, // 向下
  0,-1,0,-1, // 向左
  -1,0,-1,0 // 向上
};
int arr[200][200];
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,m,i,j,k,o,t;
  cin>>n>>m;
  for(i=0;i<n;++i)for(j=0;j<m;++j) {cin>>arr[i][j];}
  i=0,j=-1,t=2*min(n,m)+(n>m?0:-1),m+=1; // 计算打印几个方向是关键点
  for(k=0;k<t;++k){
    n+=go[k%4][2],m+=go[k%4][3];
    // cout<<endl<<"NM:"<<n<<"    "<<m<<endl;
    for(o=0;o<((k%2)?n:m);++o) {
      i+=go[k%4][0], j+=go[k%4][1];
      cout<<arr[i][j]<<" ";
    }
  }
  cout<<endl;
  return 0;
}