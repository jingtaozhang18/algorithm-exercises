// https://leetcode-cn.com/problems/maximum-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum(int a, int b) {
        long long diff=(long long)a-b;
        return diff&0x8000000000000000?b:a;
    }
};