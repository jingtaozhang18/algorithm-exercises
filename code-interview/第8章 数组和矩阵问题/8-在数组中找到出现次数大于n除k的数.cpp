#include<bits/stdc++.h>
using namespace std;

int arr[100000];
map<int, int> mp;
map<int, int> times;
void allMinusOne(){
  vector<map<int,int>::iterator> rm;
  for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it){
    if(it->second==1) rm.push_back(it);
    else it->second--;
  }
  for(map<int,int>::iterator it:rm) mp.erase(it);
}
int main(void){
  int n,k,i,t;
  cin>>n>>k;
  for(i=0;i<n;++i) cin>>arr[i];
  for(i=0;i<n;++i){
    t=arr[i];
    if(mp.find(t)!=mp.end()){ // 新出现的元素
      if(mp.size()==k-1){ // 已满
        allMinusOne();
      }else{
        mp[t]=1;
      }
    }else{
      mp[t]++;
    }
  }
  bool flag=false;
  for(i=0;i<n;++i){
    t=arr[i];
    if(mp.find(t)!=mp.end()){ // 需要计数
      if(times.find(t)==times.end()) times[t]=1;
      else times[t]++;
    }
  }
  for(map<int,int>::iterator it=mp.begin();it!=mp.end();++it){
    if(times.find(it->first)->second>n/k) {
      cout<<it->first<<" ";
      flag=true;
    }
  }
  if(!flag) cout<<-1;
  cout<<endl;
  return 0;
}