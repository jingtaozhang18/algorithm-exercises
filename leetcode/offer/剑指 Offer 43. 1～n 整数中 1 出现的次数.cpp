// https://leetcode-cn.com/problems/1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int i,j=0,k,ans=0,acc;
        vector<int> arr;
        while(n) {arr.push_back(n%10); n/=10;}
        for(i=arr.size()-1;i>=0;--i){
            if(arr[i]>1){
                ans+=(pow(10,i)*(j+1));
            }else if(arr[i]==1){
                acc=0;
                for(k=i-1;k>=0;--k) acc*=10,acc+=arr[k];
                ans+=((pow(10,i)*j)+acc+1);
            }else if(arr[i]==0){
                ans+=(pow(10,i)*j);
            }
            j*=10,j+=arr[i];
        }
        return ans;
    }
};