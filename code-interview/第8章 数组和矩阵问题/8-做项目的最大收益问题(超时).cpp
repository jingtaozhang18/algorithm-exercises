#include<bits/stdc++.h>
using namespace std;

int c[100000];
int p[100000];

// 添加记忆，减少计算量
map<pair<int,int>, int>  stringmap;

int go(int w, int k, int n){ // 计算还有w钱k步的时候能获得的最大收获
    pair<int,int> s=make_pair(w, k);
    if(stringmap.find(s) != stringmap.end())
        return stringmap[s];
    if(!k) return w;
    int i,j,a=0;
    for(i=0;i<n;++i)
        if(w>c[i])
            a=max(a, go(w+p[i], k-1, n));
    stringmap[s]=a;
    return a;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,w,k,i,j;
    cin>>n>>w>>k;
    for(i=0;i<n;++i)cin>>c[i];
    for(i=0;i<n;++i)cin>>p[i];
    cout<<go(w,k,n);
    return 0;
}