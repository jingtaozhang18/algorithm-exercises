#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

class Queue{
    public:
        void add(int val){
            sa.push(val);
        }
        void poll(){
            if(sb.empty()){
                while(!sa.empty()){
                    sb.push(sa.top());
                    sa.pop();
                }
            }
            sb.pop();
        }
        int peek(){
            if(sb.empty()){
                while(!sa.empty()){
                    sb.push(sa.top());
                    sa.pop();
                }
            }
            return sb.top();
        }
    private:
        stack<int> sa;
        stack<int> sb;
};

int main(void){
    int N;
    string op;
    int val;
    Queue mem;
    cin>>N;
    while(N--){
        cin>>op;
        if(op=="add"){
            cin>>val;
            mem.add(val);
        }else if(op=="poll"){
            mem.poll();
        }else if(op=="peek"){
            cout<<mem.peek()<<endl;
        }
    }
    return 0;
}