// https://leetcode-cn.com/problems/can-place-flowers/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int start=-2,i,gap,ans=0;
        for(i=0;i<flowerbed.size();i++)
            if(flowerbed[i]) 
                gap=i-start-1, ans+=(gap/2)-(gap%2?0:1), start=i; // 结算
        i++, gap=i-start-1, ans+=(gap/2)-(gap%2?0:1); // 结算
        return n<=ans;
    }
};