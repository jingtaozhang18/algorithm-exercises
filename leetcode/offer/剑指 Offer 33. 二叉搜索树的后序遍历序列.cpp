// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isok(vector<int>& arr, int i, int j){
        if(j-i+1<=1) return true;
        int k,t;
        for(k=i;k<=j;++k){
            if(arr[k]<arr[j]) continue;
            else break;
        }
        t=k;
        for(;t<j;++t) if(arr[t]<arr[j])return false;
        return isok(arr, i, k-1) && isok(arr, k, j-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return isok(postorder, 0, postorder.size()-1);
    }
};