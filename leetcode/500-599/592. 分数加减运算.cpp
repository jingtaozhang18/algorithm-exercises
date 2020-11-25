// https://leetcode-cn.com/problems/fraction-addition-and-subtraction/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jread_num(string expression, int&i){
      bool flag=expression[i]=='-'; int ans=0;
      if(expression[i]=='+'||expression[i]=='-') i++;
      for(;expression[i]>='0'&&expression[i]<='9';++i) ans*=10, ans+=expression[i]-'0';
      return flag?-1*ans:ans;
    }

    bool jread_fraction(string&expression, int&i, int&zi, int&mu){
      if(i==expression.size()) return false;
      zi=jread_num(expression,i);
      i++;
      mu=jread_num(expression,i);
      return true;
    }

    int gcd(int a, int b){
      return b==0?a:gcd(b, a%b);
    }

    string jtostring(int i){
      string ans="";
      char c;
      while(i) c='0'+i%10, ans=c+ans, i/=10;
      if(ans.size()==0) return "0";
      else return ans;
    }

    string fractionAddition(string expression) {
      int a_zi, a_mu, b_zi=1, b_mu=1, t_zi, t_mu, i=0;
      string ans="";
      bool flag=false;
      jread_fraction(expression,i,a_zi,a_mu);
      while(jread_fraction(expression,i,b_zi,b_mu)) t_zi=a_zi*b_mu+a_mu*b_zi, t_mu=a_mu*b_mu, a_zi=t_zi, a_mu=t_mu;
      if(a_mu>0&&a_zi<0) flag=true; if(a_mu<0&&a_zi>0) flag=true;
      if(a_zi==0) flag=false;
      if(a_mu<0) a_mu*=-1; if(a_zi<0) a_zi*=-1;
      i=gcd(a_zi, a_mu), a_zi/=i, a_mu/=i;
      if(flag) ans+='-';
      ans.append(jtostring(a_zi));
      ans+='/';
      ans.append(jtostring(a_mu));
      return ans;
    }
};