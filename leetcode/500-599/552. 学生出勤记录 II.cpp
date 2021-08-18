// https://leetcode-cn.com/problems/student-attendance-record-ii/
#include<bits/stdc++.h>
using namespace std;

// 动态规划
class Solution {
public:
    int checkRecord(int n) {
        long long  x0, y0, z0, x1, y1, z1, nx0=1, ny0=1, nz0=0, nx1=1, ny1=0, nz1=0, mod=1e9+7;
        while(--n){
            x0=nx0, y0=ny0, z0=nz0, x1=nx1, y1=ny1, z1=nz1;
            nx0=(x0+y0+z0)%mod;
            ny0=x0;
            nz0=y0;
            nx1=(nx0+(x1+y1+z1)%mod)%mod;
            ny1=x1;
            nz1=y1;
        }
        return ((nx0+ny0+nz0)%mod+(nx1+ny1+nz1)%mod)%mod;
    }
};