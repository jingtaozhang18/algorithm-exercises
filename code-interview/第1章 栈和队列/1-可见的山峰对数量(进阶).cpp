#include<iostream>
#include<stack>
using namespace std;
struct record{
  int val;
  int times;
  record(int val):val(val),times(1){};
};
int c(int val){
  int ans=1;
  ans = (val*(val-1))>>1; // 注意提高计算效率
  return ans;
};
int mem[1000000];
int main(){
  int N,i,pos_i;
  scanf("%d",&N);
  int max_pos=0;
  for(i=0;i<N;++i){
    scanf("%d",&mem[i]);
    if(mem[i]>mem[max_pos])
      max_pos=i; // 找到最大下标
  }
  stack<record> sta;
  sta.push(record(mem[max_pos]));
  int ans=0;
  for(i=1;i<N;++i){
    pos_i=(i+max_pos)%N;
    if(mem[pos_i]<sta.top().val){
      sta.push(record(mem[pos_i]));
    }else{
      while(mem[pos_i]>sta.top().val){ //弹出不满足要求的元素
        record t=sta.top();
        sta.pop();
        ans+=(2*t.times);
        ans+=((t.times==1)?0:c(t.times));
      }
      if(mem[pos_i]==sta.top().val){
        (sta.top()).times+=1;
      }else{
        sta.push(record(mem[pos_i]));
      }
    }
  }
  while(!sta.empty()){
    record t=sta.top(); // 写好逻辑之后，不要随意更改
    sta.pop();
    if(sta.size()>1){
      // 之前的
      ans+=(2*t.times);
    }else if(sta.size()==1){
      // 倒数第二个
      ans+=(((sta.top()).times==1)?t.times:2*t.times);
    }else{
      // 最后一个
    }
    ans+=(t.times==1?0:c(t.times));
  }
  cout<<ans<<endl;
}