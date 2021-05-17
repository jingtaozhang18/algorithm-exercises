// 给两个等长数组A和B，拼凑出数组C
// C[i]从{A[i], B[i]}中任取一个
// 对于任一个数组C，都有一个最小没有在数组中出现的正整数X
// 从所有C的X中找出最小的那个
// 数组长度为[1...100,000]

// 回忆的答案，不一定准确
#include<bits/stdc++.h>
using namespace std;

int solution(vector<int>& A, vector<int>& B){
    unordered_set<int> st;
    int i, n=A.size(), maxv=0;
    for(i=0;i<n;++i){
        if(A[i]==B[i]) st.insert(A[i]);
        maxv=max(max(A[i], B[i]), maxv);
    }
    for(i=1;i<=maxv+1;++i){
        if(st.find(i)==st.end()) return i;
    }
    return maxv+1;
}