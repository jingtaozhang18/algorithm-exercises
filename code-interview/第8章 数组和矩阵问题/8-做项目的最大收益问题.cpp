#include<bits/stdc++.h>
using namespace std;

struct pro{
    int cost;
    int profit;
    pro(int c, int p):cost(c),profit(p){}
};

struct cmp1{
    bool operator()(const pro &a, const pro &b) const{
        return a.cost > b.cost;
    }
};

struct cmp2{
    bool operator()(const pro &a, const pro &b) const{
        return a.profit < b.profit;
    }
};

priority_queue<pro, vector<pro>, cmp1> cp; // 开销的最小堆
priority_queue<pro, vector<pro>, cmp2> fp; // 收益的最大堆
int arr_cost[100000];
int arr_profit[100000];
int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k,i,j,c,p;
    long long w; // 累计收益会越int的界
    cin>>n>>w>>k;
    for(i=0;i<n;++i) cin>>arr_cost[i];
    for(i=0;i<n;++i) cin>>arr_profit[i];
    for(i=0;i<n;++i) cp.push(pro(arr_cost[i],arr_profit[i]));
    bool flag=true;
    while(flag){
        flag=false;
        while(!cp.empty() && cp.top().cost<w){
            fp.push(cp.top());
            cp.pop();
        }
        if(k && !fp.empty()){
            w += fp.top().profit;
            fp.pop();
            k--,flag=true;
        }
    }
    cout<<w;
    return 0;
}