#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int dp[100000];
int dends[100000];
int dright;

int halfSearch(int tar){ // 二分查找dends[0,right]中第一个比tar大的位置下标，-1表示没有找到
  int L=0,R=dright,M=(L+R)>>1;
  while(R>L){ // 继续查找的条件，范围内有两个以上的元素
    if(dends[M]>=tar) R=M; // 右边界不忽视M
    else L=M+1; // 左边界忽视M
    M=(L+R)>>1;
  }
  if(dends[L]>=tar) return L;
  else return -1;
}

int makeDp(int n){ // 动态规划，计算dp数组,返回dp值最大的下标的最后一个
  int i, index,ans=0;
//  printf("dp:");
  for(i=1;i<n;++i){
    index=halfSearch(arr[i]);
//    printf("[%d](%d)",i,index);
    if(index==-1) dp[i]=++dright,dends[dright]=arr[i];
    else dends[index]=arr[i],dp[i]=index;
    ans=dp[i]>=dp[ans]?i:ans;
//    printf("%d ",dp[i]);
  }
//  printf("\n");
  return ans;
}

void print(int n){ // n: dp值最大的下标的最后一个
//  printf("print: %d\n", n);
  int i;
  stack<int> sta;
  for(i=n-1;i>=0;--i){
    if(arr[i]<arr[n] && dp[i]==dp[n]) n=i; // 字典序更小
    else if(arr[i]<arr[n] && dp[i]==dp[n]-1){ // 找到上一个元素
      sta.push(arr[n]);
      n=i;
    }
  }
  sta.push(arr[n]);
  while(!sta.empty()){
    printf("%d ",sta.top());
    sta.pop();
  }
  printf("\n");
}

int main(void){
  int n,i;
  scanf("%d",&n);
  if(n==0){printf("\n"); return 0;}
  for(i=0;i<n;++i)scanf("%d",&arr[i]);
  dends[0]=arr[0],dp[0]=0;
  n=makeDp(n);
  print(n);
  return 0;
}