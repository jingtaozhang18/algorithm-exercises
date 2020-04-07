#include<iostream>
#include<deque>
using namespace std;

int mem[1000000];
int N,num;

int main(void){
  scanf("%d%d",&N,&num);
  int i, left, right, ans;
  for(i=0;i<N;++i) scanf("%d", &mem[i]);
  deque<int> dmax;
  deque<int> dmin;
  dmax.push_back(0);
  dmin.push_back(0);
  ans=left=right=0;
  for(left=0;left<N;++i){
    while(right<N&&mem[dmax.front()]-mem[dmin.front()]<=num){
      right++; if(right==N)break;
      while(!dmax.empty()&&mem[dmax.back()]<=mem[right])dmax.pop_back();
      dmax.push_back(right);
      while(!dmin.empty()&&mem[dmin.back()]>=mem[right])dmin.pop_back();
      dmin.push_back(right);
    }
    ans+=(right-left);
    left++;
    while(!dmax.empty()&&dmax.front()<left)dmax.pop_front();
    while(!dmin.empty()&&dmin.front()<left)dmin.pop_front();
  }
  cout<<ans<<endl;
  return 0;
}