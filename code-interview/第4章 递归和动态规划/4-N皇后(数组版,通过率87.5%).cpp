#include<bits/stdc++.h>
using namespace std;
int n;
int arr[14]; // [i] 第i行时，放置的位置
bool isValid(int i, int j){ // 第i行放到j位置上
  for(int k=0;k<i;++k){
    if(arr[k]==j || abs(arr[k]-j)==abs(k-i))
      return false;
  }
  return true;
}
int func(int i){ // 当前放置的行
  if(i==n) return 1;
  int ans=0;
  for(int j=0;j<n;++j){
    if(isValid(i,j))
      arr[i]=j,ans+=func(i+1);
  }
  return ans;
}

int main(void){  
  scanf("%d", &n);
  printf("%d\n",func(0));
  return 0;
}