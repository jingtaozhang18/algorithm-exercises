#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
class MinStack{
    public:
        MinStack(){}
        void push(int val){
            data.push(val);
            if(minData.empty() || val<=minData.top()){
                minData.push(val);
            }
        }
        void pop(){
            int val=data.top();
            data.pop();
            if(val==minData.top()){
                minData.pop();
            }
        }
        int getMin(){
            return minData.top();
        }
    private:
        stack<int>data;
        stack<int>minData;
};
int main(void){
    int N;
    cin>>N;
    string op;
    int val;
    MinStack mem;
    while(N--){
        cin>>op;
        if(op=="push"){
            cin>>val;
            mem.push(val);
        }else if(op=="pop"){
            mem.pop();
        }else if(op=="getMin"){
            cout<<mem.getMin()<<endl;
        }
    }
    return 0;
}