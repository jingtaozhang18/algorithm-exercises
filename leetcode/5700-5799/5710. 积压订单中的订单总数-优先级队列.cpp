// https://leetcode-cn.com/contest/weekly-contest-233/problems/number-of-orders-in-the-backlog/
#include<bits/stdc++.h>
using namespace std;

struct nb{
    int p, a;
    nb(int p, int a):p(p),a(a){};
    bool operator<(const nb& other) const{
        return this->p<other.p;
    }
};
struct ns{
    int p, a;
    ns(int p, int a):p(p),a(a){};
    bool operator<(const ns& other) const{
        return this->p>other.p;
    }
};
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<nb,vector<nb>> buy;
        priority_queue<ns,vector<ns>> sell;
        int i, n=orders.size();
        for(i=0;i<n;++i){
            // cout<<i<<endl;
            if(orders[i][2]==1){ // sell
                while(buy.size()&&orders[i][1]&&buy.top().p>=orders[i][0]){ // 抵消订单
                    // cout<<buy.top().p<<" "<<orders[i][0]<<" "<<min(orders[i][1], buy.top().a)<<endl;
                    nb x = buy.top(); buy.pop();
                    if(x.a>orders[i][1]){
                        x.a-=orders[i][1], orders[i][1]=0;
                        buy.push(x);
                    }else if(x.a<orders[i][1]){
                        orders[i][1]-=x.a;
                    }else{ // 相等的话
                        orders[i][1]=0;
                    }
                }
                if(orders[i][1]) sell.push(ns(orders[i][0], orders[i][1]));
            }else{
                while(sell.size()&&orders[i][1]&&sell.top().p<=orders[i][0]){ // 抵消订单
                    // cout<<sell.top().p<<" "<<orders[i][0]<<" "<<min(orders[i][1], sell.top().a)<<endl;
                    ns x = sell.top(); sell.pop();
                    if(x.a>orders[i][1]){
                        x.a-=orders[i][1], orders[i][1]=0;
                        sell.push(x);
                    }else if(x.a<orders[i][1]){
                        orders[i][1]-=x.a;
                    }else{ // 相等的话
                        orders[i][1]=0;
                    }
                }
                if(orders[i][1]) buy.push(nb(orders[i][0], orders[i][1]));
            }
        }
        int size=0, m=1e9+7;
        while(sell.size()) {size+=sell.top().a; size%=m; sell.pop();}
        while(buy.size()) {size+=buy.top().a; size%=m; buy.pop();}
        return size;
    }
};