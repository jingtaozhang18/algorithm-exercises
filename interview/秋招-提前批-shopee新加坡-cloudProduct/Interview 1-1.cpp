// 只有正整数和加乘符号的计算器
#include<bits/stdc++.h>
using namespace std;

int readNum(string& str, int& index){
    int ans=0;
    while(index<str.size()&&str[index]>='0'&&str[index]<='9'){
        ans*=10;
        ans+=(str[index]-'0');
        index++;
    }
    return ans;
}

int calc(string& str){
    stack<int> sta;
    char op='+';
    int i, x, y;
    for(i=0;i<str.size();++i){
        x=readNum(str, i);
        if(op=='+'){
            sta.push(x);
        }else{
            y=sta.top();
            sta.pop();
            sta.push(x*y);
        }
        if(i<str.size()) {
            op=str[i];
        }
    }
    x=0;
    while(sta.size()){
        x+=sta.top();
        sta.pop();
    }
    return x;
}

int main(void){
    string input="1+2+3*4*5+2";
    cout<<calc(input)<<endl;
    return 0;
}