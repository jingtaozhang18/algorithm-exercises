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

// 复习
class Solution {
public:
    int countDigitOne(int n) {
      long long i, ans=0;
      for(i=1;i<=n;i*=10){ // i代表位数
        ans+=(long long)n/(i*10)*i; // 第i位，每pow(10, i) 出现pow(10, i-1)次
        if(n%(i*10)>=i) 
          ans+=min(n%(i*10), 2*i-1)-i+1; // 余数部分的计算，第i位，min(i%pow(10, i+1), 2*pow(10, i)-1) - pow(10, i-1) + 1
      }
      return ans;
    }
};

// 复习
class Solution {
public:
    int countDigitOne(int n) {
      long long ans=0, x, y; // 注意数值范围
      for(x=1,y=10;x<=n;x*=10, y*=10){
        ans+=(long long) n / y * x; // 完整的出现次数
        if(n%y>=x) ans+=min(n%y, 2*x-1)-x+1;
      }
      return ans;
    }
};
