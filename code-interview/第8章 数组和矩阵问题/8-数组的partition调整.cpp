#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int main(void){
  int n,i,j,t;
  scanf("%d", &n);
  for(i=0;i<n;++i) scanf("%d", &arr[i]);
  for(i=0,j=0;i<n;++i)
    if(arr[i]!=arr[j]) swap(arr[i], arr[++j]);
  for(i=0;i<n;++i) printf("%d ", arr[i]);
  return 0;
}