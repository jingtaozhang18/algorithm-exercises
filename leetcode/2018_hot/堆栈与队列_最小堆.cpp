#include<stack>
#include<iostream>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> data;
    stack<int> mindata;
    MinStack() {

    }
    
    void push(int x) {
        data.push(x);
        if (mindata.empty() || x<mindata.top()) mindata.push(x); // top 之前判断是否为空
        else mindata.push(mindata.top());
    }
    
    void pop() {
        data.pop();
        mindata.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return mindata.top();
    }
};

int main(){
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    obj->pop();
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
    return 0;
}