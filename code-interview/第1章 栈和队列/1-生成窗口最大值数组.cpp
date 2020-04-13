#include<iostream>
#include<deque>
#include<stack>
using namespace std;
int mem[1000000];

int main(void){
    int N,W,i,val;
    deque<int> deq;
    cin>>N>>W;
    if(W==1){
        while(N--){
            cin>>val;
            cout<<val<<" ";
        }
        return 0;
    }
    for(i=0;i<N;i++){
        cin>>mem[i];
    }
    deq.push_back(0);
    for(i=0;i<N;++i){
        if(mem[i]>mem[deq.front()]) deq.push_front(i);
        else{
            while(mem[deq.back()]<mem[i]) {
                deq.pop_back();
            }
            deq.push_back(i);
        }
        while(deq.front()<i+1-W) deq.pop_front();
        if(i+1>=W) cout<<mem[deq.front()]<<" ";
    }
    cout<<endl;
    return 0;
}