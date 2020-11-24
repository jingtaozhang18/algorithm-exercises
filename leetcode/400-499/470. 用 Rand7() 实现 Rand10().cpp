// https://leetcode-cn.com/problems/implement-rand10-using-rand7/
#include<bits/stdc++.h>
using namespace std;

// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int ans;
        while((ans=7*(rand7()-1)+rand7())>40);
        return (ans-1)%10+1;
    }
};