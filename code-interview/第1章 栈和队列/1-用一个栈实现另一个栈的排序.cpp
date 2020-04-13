#include<iostream>
#include<stack>
using namespace std;

int main(void){
    stack<int> sta;
    stack<int> help;
    int N, val;
    cin>>N;
    while(N--){
        cin>>val;
        help.push(val);
    }
    while(!help.empty()){
        sta.push(help.top());
        help.pop();
    }
    while(!sta.empty()){
        int cur=sta.top();
        sta.pop();
        while(!help.empty()&&help.top()<cur){
            sta.push(help.top());
            help.pop();
        }
        help.push(cur);
    }
    while(!help.empty()){
        sta.push(help.top());
        help.pop();
    }
    while(!sta.empty()){
        cout<<sta.top()<<" ";
        sta.pop();
    }
    cout<<endl;
    return 0;
}