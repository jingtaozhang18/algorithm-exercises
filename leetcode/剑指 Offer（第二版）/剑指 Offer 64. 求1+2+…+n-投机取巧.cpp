// https://leetcode-cn.com/problems/qiu-12n-lcof/submissions/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumNums(int n) {
        n && (n+=sumNums(n-1));
        return n;
    }
};