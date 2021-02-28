// https://leetcode-cn.com/problems/monotonic-array/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int i, size=A.size(), flag=0; // 0 未知 1 升序 -1 降序
        for(i=1;i<size;++i){
            if(A[i]>A[i-1]){ // 升序
                if(flag<0) return false;
                flag=1;
            }else if(A[i]<A[i-1]){ // 降序
                if(flag>0) return false;
                flag=-1;
            }
        }
        return true;
    }
};