#include<bits/stdc++.h>
using namespace std;

int arr[100000];

int merge(map<int, int>& mp, int less, int more){
  int left=less-mp[less]+1;
  int right=more+mp[more]-1;
  int len=right-left+1;
  mp[left]=len;
  mp[right]=len;
  return len;
}

int main(void){
  int n,i,ans=0;
  scanf("%d",&n);
  for(i=0;i<n;++i)scanf("%d",&arr[i]);
  map<int, int> mp; // 最左边界和最右边界的最大范围
  for(i=0;i<n;++i){
    if(mp.find(arr[i])==mp.end()){ // 没有出现才有意义
      mp[arr[i]]=1;
      if(mp.find(arr[i]-1)!=mp.end()){ // 一定是在拼接
        ans=max(ans, merge(mp, arr[i]-1, arr[i]));
      }
      if(mp.find(arr[i]+1)!=mp.end()){
        ans=max(ans, merge(mp, arr[i], arr[i]+1));
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}