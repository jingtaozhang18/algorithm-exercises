#include<bits/stdc++.h>
using namespace std;

bool cmp(string& a, string &b){ // 
  if(a.size()!=b.size()) return false;
  for(int i=0;i<a.size();++i) if(a[i]!=b[i]) return false;
  return true;
}
int main(){
  ios_base::sync_with_stdio(false); // 比 printf的效率更高
  cin.tie(0);
  int n, i, pos1=-1, pos2=-1, ans;
  string str1, str2, str; // 需要初始化
  cin>>n>>str1>>str2;
  ans=n;
  for(i=0;i<n;++i){
    cin>>str;
    if(cmp(str1,str)){
      pos1=i;
      if(pos2!=-1) ans=min(ans, i-pos2);
    }
    if(cmp(str2,str)){
      pos2=i;
      if(pos1!=-1) ans=min(ans, i-pos1);
    }
  }
  cout<<(ans==n?-1:ans)<<endl;
  return 0;
}