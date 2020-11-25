// https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
      long long ans=0;
      int i,a,b,c;
      priority_queue<int,vector<int>,greater<int>> q1; 
      priority_queue<int,vector<int>,greater<int>> q2; 
      for(auto i: nums){
        if(i%3==1) q1.push(i);
        else if(i%3==2) q2.push(i);
        ans+=i;
      }
      if(ans%3==1){
        if(q2.size()<2) return ans-q1.top();
        else {
          a=q1.top(), b=q2.top(); 
          q2.pop();
          c=q2.top();
          if(a<b+c) return ans-a;
          else return ans-b-c;
        } 
      }else if(ans%3==2){
        if(q1.size()<2) return ans-q2.top();
        else {
          a=q2.top(), b=q1.top(); 
          q1.pop();
          c=q1.top();
          if(a<b+c) return ans-a;
          else return ans-b-c;
        } 
      }
      return ans;
    }
};