// https://leetcode-cn.com/problems/xor-operation-in-an-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int xorOperation(int n, int start) {
        int acc=0, i;
        for(i=0;i<n;++i) acc^=(start+2*i);
        return acc;
    }
};