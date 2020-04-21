#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int main(void){
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;++i) scanf("%d", &arr[i]);
  int jump, cur, next; // 当前跳的步数，在跳当前步数的情况下能到的最远的位置，再多跳一次能到的最远的位置
  jump=cur=next=0;
  for(i=0;i<n;++i){
    if(cur==i){ // 已经到了当前的最远位置
      jump++;
      next=max(i+arr[i], next);
      cur=next;
    }else{
      next=max(next, i+arr[i]);
    }
    if(next>=n-1) {printf("%d\n", jump+1); return 0;}
  }
  printf("%d\n", -1);
  return 0;
}