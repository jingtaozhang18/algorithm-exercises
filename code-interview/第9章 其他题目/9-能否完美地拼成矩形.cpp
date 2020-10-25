// https://www.nowcoder.com/practice/6ac90bbac4034076840e76ac5044f4a2?tpId=101&&tqId=33129&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include<bits/stdc++.h>
using namespace std;
struct point{
  int x,y;
  point(int x, int y):x(x),y(y){};
  bool operator<(point const&other) const{
    if(x!=other.x) return x<other.x;
    else return y<other.y;
  }
};
void ds(int x, int y, set<point>&s){
  point p=point(x,y);
  set<point>::iterator pp=s.find(p);
  if(pp==s.end()) s.insert(p);
  else s.erase(pp);
}

int main(void){
  int n,i,a,b,c,d,sa,sb,sc,sd,area=0;
  cin>>n;
  set<point> s;
  for(i=0;i<n;++i){
    cin>>a>>b>>c>>d;
    area+=(c-a)*(d-b);
    if(i==0) sa=a,sb=b,sc=c,sd=d;
    else sa=min(sa,a),sb=min(sb,b),sc=max(sc,c),sd=max(sd,d);
    ds(a,b,s); ds(c,b,s); ds(a,d,s); ds(c,d,s);
    // cout<<s.size()<<endl;
  }
  if((sc-sa)*(sd-sb)==area&&s.size()==4) cout<<"Yes";
  else cout<<"No";
  return 0;
}