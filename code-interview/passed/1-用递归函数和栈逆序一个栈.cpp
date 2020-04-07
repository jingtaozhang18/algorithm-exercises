#include<iostream>
#include<stack>
using namespace std;

int getLastVal(stack<int>&mem){
    int result=mem.top();
    mem.pop();
    if(mem.empty()) return result;
    else {
        int val=getLastVal(mem);
        mem.push(result);
        return val;
    }
}

void reverse(stack<int>&mem){
    if(!mem.empty()){
        int val=getLastVal(mem);
        reverse(mem);
        mem.push(val);
    }
}


int main(void){
    int N,val;
    stack<int> mem;
    cin>>N;
    while(N--){
        cin>>val;
        mem.push(val);
    }
    reverse(mem);
    
    stack<int> rm;
    while(!mem.empty()){
        rm.push(mem.top());
        mem.pop();
    }
    while(!rm.empty()){
        cout<<rm.top()<<" ";
        rm.pop();
    }
    cout<<endl;
    return 0;
}