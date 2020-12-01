// https://leetcode-cn.com/problems/create-maximum-number/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool jjudge(vector<int>&a, vector<int>&b, int i, int j){
      for(;i<a.size()&&j<b.size();++i,++j){
        if(a[i]>b[j]) return true;
        else if(a[i]<b[j]) return false; 
      }
      return j==b.size();
    }
    void jmerge(vector<int>&a, vector<int>&b, vector<int>&res){
      int i=0,j=0,k=0,m=a.size(),n=b.size(),t;
      vector<int> ans(m+n);
      while(i<m||j<n){
        if(i==m) ans[k++]=b[j++];
        else if(j==n) ans[k++]=a[i++];
        else{
          if(jjudge(a,b,i,j)) ans[k++]=a[i++];
          else ans[k++]=b[j++];
        }
      }
      for(i=0;i<m+n;++i) if(ans[i]>res[i]){res=ans; return;} else if(ans[i]<res[i]) return;
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