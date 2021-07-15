// 一条路的两个车道，有地方平坦，有地方坑洼，两个车道用两个字符串描述
// 每个车道，至多可以选择一条连续的路段进行坑洼修补（连续路段中允许存在平坦的路段）
// 在保证车辆可以通行过该路的前提下，输出可以维修的最多的坑洼块儿
// 例如
// ..x.xxxx
// .xxx...x
// .表示平坦，x表示坑洼；可维修的最多块儿为6个
// 如下图所示
// . .x .(xxxx)
// .(xx)x ...x

// 回忆的答案，不一定准确
#include<bits/stdc++.h>
using namespace std;

int solution(string &L1, string &L2){
    int n=L1.size(), i, ans=0;
    int a[n+1];
    int b[n+1];
    a[0]=b[0]=0;
    for(i=0;i<n;++i){
        a[i+1]=a[i]+(L1[i]=='#'?1:0);
        b[i+1]=b[i]+(L2[i]=='#'?1:0);
    }
    for(i=0;i<n;++i){
        if(i==0) ans=max(a[n], b[n]);
        else{
            ans=max(max(a[i-1]+b[n]-b[i], b[i-1]+a[n]-a[i]), ans);
        }
    }
    return ans;
}