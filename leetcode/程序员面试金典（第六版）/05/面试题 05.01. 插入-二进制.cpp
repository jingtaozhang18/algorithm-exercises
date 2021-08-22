// https://leetcode-cn.com/problems/insert-into-bits-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
        unsigned int a=1, t;
        for(t=0;t<i;++t) a<<=1, M=(unsigned int)M<<1;
        for(;t<j;++t) a=(a<<1)|a;
        // cout<<bitset<32>(a)<<endl;
        // cout<<bitset<32>(N)<<endl;
        // cout<<bitset<32>(N|a)<<endl;
        // cout<<bitset<32>(M)<<endl;
        // cout<<bitset<32>(M|(~a))<<endl;
        // cout<<bitset<32>(169972585)<<endl;
        // cout<<bitset<32>(1243714409)<<endl;
        return (N|a)&(M|(~a));
    }
};