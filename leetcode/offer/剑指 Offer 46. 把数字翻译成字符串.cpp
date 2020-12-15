// https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jgo(vector<int>& arr, int i){
        if(i>=arr.size()) return 1;
        int n=0, a=0;
        n+=jgo(arr, i+1);
        if(arr[i]!=0&&i+1<arr.size()){ // 两个数字的时候，第一个数字不能是0
            a=arr[i]*10+arr[i+1];
            if(a>=0&&a<=25) n+=jgo(arr, i+2);
        }
        return n;
    }

    int translateNum(int num) {
        stack<int> sta;
        vector<int> arr;
        while(num){ sta.push(num%10); num/=10; }
        while(!sta.empty()) { arr.push_back(sta.top()); sta.pop();}
        return jgo(arr, 0);
    }
};