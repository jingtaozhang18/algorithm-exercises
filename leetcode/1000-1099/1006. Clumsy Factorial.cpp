// https://leetcode-cn.com/problems/clumsy-factorial/
// 1006. 笨阶乘
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int clumsy(int N) {
        long long ans=0;
        bool flag=true; // 加法
        while(N>=1){
            if(N>=3){
                if(flag) ans+=(N*(N-1)/(N-2));
                else ans-=(N*(N-1)/(N-2));
                ans+=N-3;
                N-=4;
            }else if(N==2){
                if(flag) ans+=N*(N-1);
                else ans-=N*(N-1);
                N-=2;
            }else{
                if(flag) ans+=N;
                else ans-=N;
                N-=1;
            }
            flag=false;
        }
        return ans;
    }
};