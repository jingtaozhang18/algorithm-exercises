#include<bits/stdc++.h>
using namespace std;

int main(void){
  // 加快IO速度
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  // 比set的速度要快，使用set的时候，大概率会超时
  unordered_set<int> st;
  int n,i,j,t,ans=1,vmin,vmax;
  cin>>n;
  vector<int> arr(n);
  for(i=0;i<n;++i) cin>>arr[i];
  for(i=0;i<n;++i){
    st.clear();
    st.insert(arr[i]);
    vmax=vmin=arr[i];
    for(j=i+1;j<n;++j){
      // 子数组的判断时间从O(log(n))降低到O(1)
      if(st.find(arr[j])==st.end()){
        st.insert(arr[j]);
        vmax=max(arr[j],vmax);
        vmin=min(arr[j],vmin);
        if(vmax-vmin==j-i) ans=max(ans,j-i+1);
      }else break;
    }
  }
  cout<<ans<<endl;
  return 0;
}