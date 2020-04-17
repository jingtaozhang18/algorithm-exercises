#include<bits/stdc++.h>
using namespace std;
#define gc() (p1==p2&&(p1=bf,p2=bf+fread(bf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char bf[1 << 21], *p1 = bf, *p2 = bf;
template<class T> void read(T& x) {
    char c(gc()); T t(0); bool flg(false);
    for (; c != EOF && !isdigit(c); c = gc()) flg = c == '-';
    for (; isdigit(c); c = gc()) t = 10 * t + (c & 15);
    x = flg ? -t : t;
}
struct envelope{
  int width;
  int high;
  bool operator< (envelope const& other ) const{
    if(this->width<other.width) return true;
    else if(this->width>other.width) return false;
    else{
      if(this->high>other.high) return true;
      else return false;
    }
  }
};

envelope arr[100002];
int dp[100002];
int dends[100002];
int dright;

int halfSearch(int tar){ // 找到左边第一个比tar大或等的元素
  int L=0,R=dright,M=(L+R)>>1;
  while(R>L){
    if(dends[M]>=tar) R=M;
    else L=M+1;
    M=(L+R)>>1;
  }
  if(dends[L]>=tar) return L;
  else return -1;
}

int makeDp(int n){
  int i,index;
  dends[0]=arr[0].high;
  for(i=1;i<n;++i){
    index=halfSearch(arr[i].high);
    if(index==-1) dp[i]=++dright, dends[dright]=arr[i].high;
    else dends[index]=arr[i].high,dp[i]=index;
  }
  return dright;
}

int main(void){
  int n,i,ans_i;
  read(n);
  for(i=0;i<n;++i) read(arr[i].width),read(arr[i].high);
  sort(arr,arr+n);
  ans_i=makeDp(n);
  printf("%d\n",ans_i+1);
  return 0;
}