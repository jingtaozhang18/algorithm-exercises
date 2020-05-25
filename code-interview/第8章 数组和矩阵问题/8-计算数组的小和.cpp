#include<bits/stdc++.h>
using namespace std;

int arr[100000];
int tmp[100000];
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(0);
  int n,i,j,k,L,B,R;
  long ans=0;
  cin>>n;
  for(i=0;i<n;++i)cin>>arr[i];
  for(k=1;k<n;k*=2){ // k是合并单元的大小
    //L 左单元起始位置，R右单元起始位置，B右单元最右虚边界
    for(i=L=0,j=R=k,B=min(2*k,n);R<n;L=B,j=R=L+k,B=min(L+2*k,n)){
      while(L<R&&j<B){ //L 和 j在移动
        if(arr[L]<=arr[j]) ans+=arr[L]*(B-j),tmp[i++]=arr[L++];
        else tmp[i++]=arr[j++];
      }
      while(L<R) tmp[i++]=arr[L++];
      while(j<B) tmp[i++]=arr[j++];
    }
    while(i>0) --i,arr[i]=tmp[i]; // 此处的i并没有走到arr的最右端
  }
  cout<<ans<<endl;
  return 0;
}