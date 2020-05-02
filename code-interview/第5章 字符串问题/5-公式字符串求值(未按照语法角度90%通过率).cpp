#include<bits/stdc++.h>
using namespace std;
map<char, int> mp;
stack<char> op;
stack<int> nums;
void putNum(int val){ // 读一个数值
  nums.push(val);
}
int putOp(char opc){ // 读到一个运算符号,返回栈顶元素
  if(opc=='('){op.push(opc); return 0;}
  while(!op.empty()&&(mp[opc]<=mp[op.top()]||opc==')')){ // 强迫括号进行计算
    char c=op.top(); op.pop();
    if(c=='('&&opc==')') return nums.top();
    int a=nums.top(); nums.pop();
    int b=nums.top(); nums.pop();
    if(c=='+') nums.push(b+a);
    else if(c=='-') nums.push(b-a);
    else if(c=='*') nums.push(b*a);
    else if(c=='/') nums.push(b/a);
    //cout<<b<<c<<a<<"="<<nums.top()<<endl;
  }
  op.push(opc);
  return 0;
}

int readNum(string& str, int& i){ //读取一个数值
  int ans=0;
  while(i<str.size()&&str[i]>='0'&&str[i]<='9') ans*=10, ans+=str[i]-'0',++i;
  return ans;
}
int main(void){
  // 算术优先级
  mp['+']=1,mp['-']=1;
  mp['*']=2,mp['/']=2;
  mp[')']=0,mp['(']=0; // 实际此处的优先级无效
  string str;
  int i,val;
  cin>>str;
  i=0;
  putOp('(');
  while(i<str.size()){
    if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='('||str[i]==')'){
      putOp(str[i]);
      ++i;
    }else{
      val=readNum(str, i);
      putNum(val);
    }
    // cout<<"i:"<<i<<endl;
  }
  cout<<putOp(')')<<endl;
  return 0;
}