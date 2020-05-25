#include<bits/stdc++.h>
using namespace std;

double arr[100001];
int main(void){
  int n,i;
  double minv,maxv,ans=0,tmin,tmax;
  scanf("%d", &n);
  for(i=0;i<n;++i) scanf("%lf", &arr[i]); // 数据录入的方式
  maxv=minv=arr[0];
  for(i=1;i<n;++i){
    tmin=min(arr[i], min(minv*arr[i], maxv*arr[i]));
    tmax=max(arr[i], max(minv*arr[i], maxv*arr[i]));
    minv=tmin, maxv=tmax;
    ans=max(ans, maxv);
  }
  printf("%.2f",ans);
  return 0;
}