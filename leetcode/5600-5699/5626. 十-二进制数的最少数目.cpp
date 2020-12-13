// https://leetcode-cn.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int ans=0;
        for(char c:n) ans=max(ans, c-'0');
        return ans;
    }
};