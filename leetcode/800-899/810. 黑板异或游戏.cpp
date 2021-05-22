// https://leetcode-cn.com/problems/chalkboard-xor-game/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int acc=0, n=nums.size(), i, j;
        for(auto e:nums) acc^=e; // 异或和
        if(acc==0) return true;
        return n%2==0;
    }
};