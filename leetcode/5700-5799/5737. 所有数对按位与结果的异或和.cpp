// https://leetcode-cn.com/contest/weekly-contest-237/problems/find-xor-sum-of-all-pairs-bitwise-and/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x=0, y=0;
        for(auto &e:arr2) y^=e;
        for(auto &e:arr1) x^=(e&y);
        return x;
    }
};