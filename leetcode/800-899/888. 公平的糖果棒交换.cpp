// https://leetcode-cn.com/problems/fair-candy-swap/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int suma=0, sumb=0, i, diff, x;
        for(auto e:A) suma+=e;
        for(auto e:B) sumb+=e;
        unordered_set<int> bmp(B.begin(), B.end());
        diff=suma-sumb; diff/=2;
        for(i=0;i<A.size();++i){
            if(bmp.find(A[i]-diff)!=bmp.end()) return vector<int>{A[i], A[i]-diff};
        }
        return vector<int>{};
    }
};