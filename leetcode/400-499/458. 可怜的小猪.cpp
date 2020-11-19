// https://leetcode-cn.com/problems/poor-pigs/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int base = minutesToTest/minutesToDie + 1; // 一只猪可以包含的信息量
        int ans =0;
        while(pow(base, ans)<buckets) ans++;
        return ans;
    }
};