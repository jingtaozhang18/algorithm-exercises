#include<bits/stdc++.h>
using namespace std;

int arr[1000000];
int bi[1000001]; // 桶中最小值
int ba[1000001]; // 桶中最大值

int bucket(long long num, long long val_i, long long val_a, long long len){
    return (num-val_i)*len/(val_a-val_i);
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i,t,vi=INT_MAX,va=INT_MIN,ans=0;
    cin>>n;
    // 统计最小最大值
    for(i=0;i<n;++i){
        cin>>t;
        vi=min(vi,t),va=max(va,t);
        arr[i]=t;
    }
    if(va-vi==0){
        cout<<0;
        return 0;
    }
    // 入桶
    for(i=0;i<n;++i){
        t=bucket(arr[i], vi, va, n);
        if(!bi[t])
            bi[t]=arr[i], ba[t]=arr[i];
        else
            bi[t]=min(bi[t], arr[i]), ba[t]=max(ba[t], arr[i]);
    }
    va=0;
    for(i=0;i<n+1;++i){
        if(bi[i]) {
            ans=max(ba[i]-bi[i], ans);
            if(va) ans=max(bi[i]-va, ans);
            va=ba[i];
        }
    }
    cout<<ans;
    return 0;
}