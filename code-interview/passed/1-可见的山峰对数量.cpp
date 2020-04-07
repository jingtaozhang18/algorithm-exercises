#include<iostream>
using namespace std;
int main(void){
  int T;
  int n,p,m;
  scanf("%d", &T);
  while(T--){
    scanf("%d%d%d", &n,&p,&m);
    if(n==1) cout<<0<<endl;
    else cout<<2*n-3<<endl;
  }
  return 0;
}