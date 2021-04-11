// https://leetcode-cn.com/contest/weekly-contest-236/problems/find-the-winner-of-the-circular-game/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheWinner(int n, int k) {
        if(k==1) return n;
        int arr[n], i, j;
        for(i=0;i<n;++i) arr[i]=(i+1)%n;
        i=0;
        while(true){
            for(j=0;j<k-2;++j) i=arr[i];
            arr[i]=arr[arr[i]];
            if(arr[i]==i) break;
            i=arr[i];
        }
        return i+1;
    }
};