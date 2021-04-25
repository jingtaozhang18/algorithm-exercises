// https://app.codility.com/demo/results/demoZZ4QDT-GAA/
#include <bits/stdc++.h>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    sort(A.begin(), A.end());
    int i, d;
    for(i=0,d=1;i<A.size();++i){
        if(A[i]<1) continue;
        if(A[i]==d) {
            ++d;
            while(i+1<A.size()&&A[i+1]==A[i]) ++i; // 过掉重复的元素
        }
        else break;
    }
    return d;
}