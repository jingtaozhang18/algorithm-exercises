#include<iostream>
using namespace std;

int calc(int i, int m){
  if(i==1) return 1;
  else return (calc(i-1, m)+m-1)%i+1;
}


int main(void){
  int n,m;
  cin>>n>>m;
  cout<<(calc(n,m))<<endl;
  return 0;
}