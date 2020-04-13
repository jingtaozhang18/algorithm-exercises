# include<bits/stdc++.h>
using namespace std;

int mem[100001]; // 对0号位置进行了初始化

int main(void){
  int n,target,i,ans=0;
  scanf("%d%d",&n,&target);
  for(i=1;i<=n;++i) scanf("%d", &mem[i]);
  map<int,int>mp; //<a, b> 和为a出现的最早位置
  mp[0]=0; // 初始化，很重要
  for(int i=1;i<=n;++i){
    mem[i]+=mem[i-1]; // sum为mem[i]
    auto p=mp.find(mem[i]-target);
    if(p!=mp.end()){ // 找到符合要求的序列
      ans=max(ans,i-p->second);
    }
    if(mp.find(mem[i])==mp.end()) mp[mem[i]]=i;
  }
  cout<<ans<<endl;
  return 0;
}