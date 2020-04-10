#include<queue>     // 队列或者优先级队列
#include<vector>    // 数组
#include<iostream>  // cout 
using namespace std;

void func(int * a){ // 传值
    a++;
    cout<<(*a)<<endl;
}

int main(void){
    int *a=new int[4];
    a[0]=1,a[1]=2,a[2]=3,a[3]=4;
    func(a);
    cout << *a <<endl;

    // 优先级队列
    priority_queue<int, vector<int>, greater<int> > pq_min; // 最小堆
    priority_queue<int, vector<int>, less<int> > pq_max;    // 最大堆
    pq_min.push(1);
    pq_min.push(2);
    while(!pq_min.empty()){cout << pq_min.top() << "\t"; pq_min.pop();} cout<<endl;
    return 0;
}
