#include<bits/stdc++.h>
using namespace std;

int mem[1000];
int n,ans=INT_MAX;
map<int, int>mp[1000]; // <(index,target), count> 提炼出状态来
int calc(int index, int count, int target){ // 当前节点向后满足target需要的数量
  if(index==n) return INT_MAX;
  int i, val=INT_MAX, t, ori_target=target; // i 当前使用的张数
  for(i=0;target>0;++i,target-=mem[index]){
    if(mp[index].find(target)!=mp[index].end()){
      t=mp[index][target];
      if(t!=INT_MAX) t+=i;
    }
    else{
      t=calc(index+1,count+i,target);
      if(t!=INT_MAX) t+=i;
    }
    if(val!=INT_MAX) val=min(t,val);
  }
  if(target==0) val=min(val,i);
  mp[index][ori_target]=val; // 存储信息
//  printf("%d. %d. %d\n",index,ori_target,val);
  if(val!=INT_MAX) ans=min(ans,val+count);
  return val;
}
int main(void){
  int target,i;
  scanf("%d%d",&n,&target);
  for(i=0;i<n;++i)scanf("%d",&mem[i]);
  calc(0,0,target);
  if(ans==INT_MAX) ans=-1;
  printf("%d\n",ans);
  return 0;
}