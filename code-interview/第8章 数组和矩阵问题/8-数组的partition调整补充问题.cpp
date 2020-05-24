#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int main(void){
  int n,i,l,r;
  scanf("%d", &n);
  for(i=0;i<n;++i) scanf("%d", &arr[i]);
  l=-1,i=0;r=n; // [0:l] [l+1:i) [r:] 三段
  while(i<r){
    if(arr[i]==0) swap(arr[++l],arr[i++]); // 左侧信息已排序
    else if(arr[i]==2) swap(arr[i],arr[--r]); // 右侧信息未排序
    else i++;
  }
  for(i=0;i<n;++i) printf("%d ", arr[i]);
  return 0;
}