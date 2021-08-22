// https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(int n, int m){ // 递推留下这个人的编号
        if(n==1) return 0;
        int x=jgo(n-1, m);
        return (m+x)%n;
    }
    int lastRemaining(int n, int m) {
        return jgo(n,m);
    }
};