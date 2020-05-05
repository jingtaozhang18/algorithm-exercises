#include<bits/stdc++.h>
using namespace std;

bool judge(string &str, string &exp, int i, int j){ // 判断字符串匹配情况
  if(j==exp.size()) return i==str.size(); // 无法继续匹配
  if(j+1<exp.size()&&exp[j+1]=='*'){ // 可能会出现str到头了，exp还在继续走的情况
    if(judge(str, exp, i,j+2)) return true; // 重复0次
    while(i<str.size()&&(str[i++]==exp[j]||exp[j]=='.')) if(judge(str, exp, i,j+2)) return true;
  }else{
    if(i!=str.size()&&(str[i]==exp[j]||exp[j]=='.')) return judge(str, exp,i+1,j+1);
  }
  return false;
}

int main(void){
  int i;
  string str,exp; // 题目自身保证了两个字符串一定不为空
  cin>>str>>exp;
  // 合法性检查
  for(i=0;i<str.size();++i) if(str[i]<'a'||str[i]>'z') break;
  if(i!=str.size()){cout<<"NO"<<endl; return 0;}
  if(exp[0]=='*'){cout<<"NO"<<endl; return 0;}
  for(i=0;i<exp.size();++i) 
    if((i&&exp[i]=='*'&&exp[i-1]=='*')||!((exp[i]>='a'&&exp[i]<='z')||exp[i]=='.'||exp[i]=='*')) break;
  if(i!=exp.size()){cout<<"NO"<<endl; return 0;}
  if(judge(str,exp,0,0)) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}