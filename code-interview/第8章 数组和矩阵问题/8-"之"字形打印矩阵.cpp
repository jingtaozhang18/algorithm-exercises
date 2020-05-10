#include<bits/stdc++.h>
using namespace std;

int arr[200][200];
int main(void){
  int n,m,i,j;
  cin>>n>>m;
  for(i=0;i<n;++i)for(j=0;j<m;++j)cin>>arr[i][j];
  i=0,j=0;
  if(!n&&!m)return 0;
  cout<<arr[i][j]<<" ";
  while(true){
    // 右移,移不动则下移，再移不动，遍历结束
    if(j+1<m) {j++; cout<<arr[i][j]<<" ";}
    else if(i+1<n) {i++; cout<<arr[i][j]<<" ";}
    else break;
    // 左下移动
    while(i+1<n&&j-1>=0){i++,j--;cout<<arr[i][j]<<" ";}
    // 下移，移不动则右移, 再移不动，遍历结束
    if(i+1<n) {i++; cout<<arr[i][j]<<" ";}
    else if(j+1<m){j++;cout<<arr[i][j]<<" ";}
    else break;
    // 右上移动
    while(i-1>=0&&j+1<m){i--,j++;cout<<arr[i][j]<<" ";}
  }
  return 0;
}