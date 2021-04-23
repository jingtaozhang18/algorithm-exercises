// https://app.codility.com/programmers/lessons/1-iterations/binary_gap/
#include<bits/stdc++.h>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int a=-1, b=-1, ans=0, i=0;
    unsigned int flag=1;
    while(N){
        if(flag&N){
            a=b, b=i;
            if(a!=-1) ans=max(ans, b-a-1);
        }
        ++i, flag=flag<<1;
        if(i==31) break;
    }
    return ans;
}

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int a=-1, b=-1, ans=0, i=0;
    unsigned int flag=1;
    while(N){
        if(flag&N){
            a=b, b=i;
            if(a!=-1) ans=max(ans, b-a-1);
        }
        N=(~flag)&N;
        ++i, flag=flag<<1; // 错误点，先去掉0，再移位，顺序反了
    }
    return ans;
}