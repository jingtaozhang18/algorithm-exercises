// https://leetcode-cn.com/problems/ugly-number-ii/
#include<bits/stdc++.h>
using namespace std;

// set
class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st{1};
        while(--n){
            auto x=*st.begin();
            st.erase(st.begin());
            st.insert(x*2);
            st.insert(x*3);
            st.insert(x*5);
        }
        return *st.begin();
    }
};

// 动态规划
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        if(n==3) return 3;
        int arr[n+1], i, p2=1, p3=1, p5=1;
        arr[1]=1;
        for(i=2;i<=n;++i){
            long long num2=arr[p2]*2, num3=arr[p3]*3, num5=arr[p5]*5;
            long long x=min(min(num2, num3), num5);
            if(x==num2) p2++;
            if(x==num3) p3++;
            if(x==num5) p5++;
            arr[i]=x;
        }
        return arr[n];
    }
};