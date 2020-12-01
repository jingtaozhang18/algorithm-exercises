// https://leetcode-cn.com/problems/create-maximum-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void jmerge(vector<int>&a, vector<int>&b, vector<int>&res){
      int i=0,j=0,k=0,m=a.size(),n=b.size();
      vector<int> ans(m+n);
      bool flag=false; // 新结果是否已经大于当前的最优解
      while(i<m||j<n){
        if(i==m) ans[k]=b[j++];
        else if(j==n) ans[k]=a[i++];
        else {if(a[i]>b[j]) ans[k]=a[i++]; else ans[k]=b[j++];} // 错误： 相等的时候没有办法判断选谁
        if(!flag&&ans[k]>res[k]) flag=true;
        if(!flag&&ans[k]<res[k]) return;
        ++k;
      }
      res=ans;
    }
    vector<int> jget(vector<int>& arr, int k){ // 从arr中选出k个元素使其最大
      int i,size=arr.size(),sk=k;
      k=size-k;
      stack<int> sta;
      for(i=0;i<size;++i){
        while(k&&!sta.empty()&&sta.top()<arr[i]) {sta.pop(); --k;}
        sta.push(arr[i]);
      }
      vector<int> ans(sk);
      while(k--) sta.pop();
      for(i=sk-1;i>=0;--i) {ans[i]=sta.top();sta.pop();}
      return ans;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int i,m=nums1.size(), n=nums2.size();
        vector<int> ans(k,0);
        for(i=max(k-n, 0);i<=min(m, k);++i){
            vector<int> a=jget(nums1, i);
            vector<int> b=jget(nums2, k-i);
            jmerge(a,b,ans);
        }
        return ans;
    }
};