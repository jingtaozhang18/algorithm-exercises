// https://leetcode-cn.com/problems/chou-shu-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> arr(n, 1);
        int a=0,b=0,c=0,i; // 分别对应乘以2，3，5会超过最后一个丑数的下标
        for(i=1;i<n;++i){
            arr[i]=min(min(2*arr[a], 3*arr[b]), 5*arr[c]);
            while(2*arr[a]<=arr[i]) a++;
            while(3*arr[b]<=arr[i]) b++;
            while(5*arr[c]<=arr[i]) c++;
        }
        return arr[n-1];
    }
};