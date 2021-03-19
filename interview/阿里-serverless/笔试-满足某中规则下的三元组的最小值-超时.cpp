// 长度为 n (1 <= n <= 3000) 的数组 a 和 b，找到i, j, k使得 1 <= i < j < k <= n 且 a[i] <= a[j] <= a[k]，求res = min(b[i]+b[j] +b[k])
// 8
// 9 8 6  7 7 2 9 2
// 9 1 10 8 6 4 8 6
#include<bits/stdc++.h>
using namespace std;

int a[3002];
int b[3002];

int main(void) {
    int n, i, j, k;
    long long ans=INT_MAX;
    cin>>n;
    for(i=0;i<n;++i) cin>>a[i];
    for(i=0;i<n;++i) cin>>b[i];
    for(i=0;i<n;++i){
        for(j=i+1;j<n;++j){
            for(k=j+1;k<n;++k){
                if(a[i]<=a[j]&&a[j]<=a[k]){
                    ans=min(ans, (long long)b[i]+b[j]+b[k]);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}