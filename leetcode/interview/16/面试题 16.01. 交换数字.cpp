// https://leetcode-cn.com/problems/swap-numbers-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0]=numbers[0]^numbers[1];
        numbers[1]=numbers[0]^numbers[1];
        numbers[0]=numbers[0]^numbers[1];
        return numbers;
    }
};