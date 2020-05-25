#include<bits/stdc++.h>
using namespace std;

int arr[201][201];
int wid[201][201]; //.wid[i][j] 从[i][j]位置出发向右能到的最右位置
int hig[201][201]; // hig[i][j] 从[i][j]位置向下能到的最右位置
int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,i,j,k,ans=0;
  cin>>n;
  for(i=0;i<n;++i) for(j=0;j<n;++j) cin>>arr[i][j];
  // 预处理
  for(i=n-1;i>=0;--i){
    for(j=0;j<n;++j) if(arr[i][j]) hig[i][j]=hig[i+1][j]+1;
    for(j=0;j<n;++j) if(arr[j][i]) wid[j][i]=wid[j][i+1]+1;
  }
  // 从每个位置出发找向右向下的最大矩形
  for(i=0;i<n;++i){
    for(j=0;j<n;++j){
      for(k=min(wid[i][j], hig[i][j]);k>=0;--k)
        if(hig[i][j+k-1]>=k && wid[i+k-1][j]>=k) break;
      ans=max(ans,k);
    }
  }
  cout<<ans<<endl;
  return 0;
}