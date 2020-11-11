// https://leetcode-cn.com/problems/2vYnGI/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        vector<int> *sht, *lng;
        if(staple.size()<drinks.size()) sht=&staple, lng=&drinks;
        else sht=&drinks, lng=&staple;
        int l,r=(*lng).size()-1,c,i,j,ans=0;
        for(i=0;i<(*sht).size();++i){
            l=0;
            while(l<=r){
               c=(l+r)>>1;
               if((*lng)[c]<=x-(*sht)[i]) l=c+1;
               else r=c-1; 
            }
            ans+=(r+1)%1000000007,ans%=1000000007;
        }
        return ans;
    }
};