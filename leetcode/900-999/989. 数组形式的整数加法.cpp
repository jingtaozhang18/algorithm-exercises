// https://leetcode-cn.com/problems/add-to-array-form-of-integer/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
      int i=0,j=A.size()-1,t;
      while(i<j) swap(A[i++], A[j--]);
      i=j=0;
      while(j||K){
        t=(i<A.size()?A[i]:0)+(K%10)+j;
        if(i<A.size()) A[i]=t%10;
        else A.push_back(t%10);
        j=t/10, K=K/10, ++i;
      }
      i=0,j=A.size()-1;
      while(i<j) swap(A[i++], A[j--]);
      return A;
    }
};