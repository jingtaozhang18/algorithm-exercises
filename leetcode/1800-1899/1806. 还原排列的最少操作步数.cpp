// https://leetcode-cn.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reinitializePermutation(int n) {
        int i=1, ans=0;
        do{
            if(i%2){ // ji
                i = n / 2 + (i - 1) / 2;
            }else{
                i = i/2;
            }
            ++ans;
        }while(i!=1);
        return ans;
    }
};