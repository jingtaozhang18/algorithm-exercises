// https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/submissions/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        int i,x;
        for(x=0,i=2;i<=n;++i) x=(x+m)%i;
        return x;
    }
};