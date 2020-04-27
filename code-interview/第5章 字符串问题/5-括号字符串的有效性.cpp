#include<bits/stdc++.h>
using namespace std;

int main(void){
  ios_base::sync_with_stdio(false); // 比 printf的效率更高
  cin.tie(0);
  string str;
  cin>>str;
  int i,left=0;
  bool flag=true;
  for(i=0;i<str.size();++i){
    if(str[i]!='(' && str[i]!=')'){flag=false; break;}
    else if(str[i]=='(') left++;
    else {
      if (left==0) {flag=false; break;}
      else left--;
    }
  }
  if(flag&&!left) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}