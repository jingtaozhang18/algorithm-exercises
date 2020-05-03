#include<bits/stdc++.h>
using namespace std;

map<char,int> head; // 字符最早有效位置
map<char,int> tail; // 字符最后出现的位置
int lin[100000]; // 下一个和自己一致字符的位置
map<char, int> leave; // 剩余需要的字符数

void record(const string& str){ // 统计字符串中字符的数量
  for(char c: str){
    if(leave.find(c)!=leave.end()) leave[c]++;
    else leave[c]=1;
  }
}
int clac_len(int cur){ // 计算当前答案
  for(pair<char,int> it: leave){
    if(it.second) return INT_MAX;
  }
  int most_left=cur;
  for(pair<char,int> it: head)
    most_left=min(most_left, it.second);
//  cout<<"ans: "<<cur<<" "<<most_left<<endl;
  return cur-most_left+1;
}

int main(void){
  memset(lin, -1, sizeof lin); // 初始化 -1 没有这个位置
  string str1, str2;
  cin>>str1>>str2;
  record(str2); // 统计str2中字符的数量
  int i,ans=INT_MAX;
  char c;
  for(i=0;i<str1.size();++i){
    c=str1[i];
    if(leave.find(c)==leave.end()) continue;
    // 状态维护
    if(tail.find(c)!=tail.end()) lin[tail[c]]=i;
    tail[c]=i;
    if(leave[c]) {
      leave[c]--;
      if(head.find(c)==head.end()) head[c]=i;
      if(!leave[c]) ans=min(ans, clac_len(i));
    }else{ // 进行移动
      head[c]=lin[head[c]]; // 该字符头部后移
      ans=min(ans, clac_len(i));
    }
  }
  cout<<(ans==INT_MAX?0:ans)<<endl;
  return 0;
}