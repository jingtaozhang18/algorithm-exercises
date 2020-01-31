#include<queue>     // 队列或者优先级队列
#include<vector>    // 数组
#include<iostream>  // cout 
using namespace std;

int main(void){
    // 优先级队列
    priority_queue<int, vector<int>, greater<int> > pq_min; // 最小堆
    priority_queue<int, vector<int>, less<int> > pq_max;    // 最大堆
    pq_min.push(1);
    pq_min.push(2);
    while(!pq_min.empty()){cout << pq_min.top() << "\t"; pq_min.pop();} cout<<endl;
    return 0;
}
