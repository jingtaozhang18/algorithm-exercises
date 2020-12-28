// https://leetcode-cn.com/problems/sorted-merge-lcci/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
      int index=m+n;
      --m,--n;
      while(m>=0&&n>=0){
        if(A[m]>B[n]) A[--index]=A[m--];
        else A[--index]=B[n--];
      }
      while(m>=0) A[--index]=A[m--];
      while(n>=0) A[--index]=B[n--];
    }
};