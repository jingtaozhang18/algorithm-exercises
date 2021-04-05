// https://leetcode-cn.com/problems/SNJvJP/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orchestraLayout(int num, int x, int y) {
        int left=x, right=num-1-x, up=y, down=num-1-y;
        long long k = min({left, right, up, down}), i;
        long long index=0, a, b;
        a = (long long)num*4-4;
        b = a - 8*(k-1);
        index+=(a+b)/2*k, index%=9;
        x-=k, y-=k;
        int m = num-2*k-1;
        if(x==0) {
            index+=y, index%=9;
            return index+1;
        }else{
            index+=m;
            index%=9;
        }
        if(x&&y==m){
            index+=x, index%=9;
            return index+1;
        }else if(x&&y<m){
            index+=m;
            index%=9;
        }
        if(x==m){
            index+=m-y;
            index%=9;
            return index+1;
        }else{
            index+=m;
            index%=9;    
        }
        index+=m-x;
        index%=9;
        return index+1;
    }
};