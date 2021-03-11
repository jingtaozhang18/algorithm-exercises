// https://leetcode-cn.com/problems/exam-room/
#include<bits/stdc++.h>
using namespace std;

int NN;
struct s{
  int start, end;
  s(int _s, int _e):start(_s),end(_e){}
  int distance() const{  // 认真思考一下距离的计算公式
    if(start==-1) return end;
    if(end==NN) return NN-1-start;
    return (end+start)/2-start;
  }
  bool operator<(const s &other) const{
    int len_a=this->distance(), len_b=other.distance();
    if(len_a==len_b) return start<other.start; // 开始位置小的在前
    return len_a>len_b; // 长度大的在前
  }
};
class ExamRoom {
public:
    set<s> st;
    int n;
    ExamRoom(int N):n(N) {
      NN=N;
      st.emplace(-1, n); // 放入虚拟的段(左右都采集不到)
    }
    
    int seat() {
      int ans, start, end;
      auto p = st.begin();
      if(p==st.end()) return -1;
      start=p->start, end=p->end;
      st.erase(p); // 错误点 先删除，在插入之后再删除，会引起指针变化
      // cout<<start<<" "<<end<<endl;
      if(start==-1) {
        ans=0;
        st.emplace(ans, end);
      }else if(end==n){
        ans=n-1;
        st.emplace(start, ans);
      }else{
        ans=(start+end)/2;
        st.emplace(start, ans);
        st.emplace(ans, end);
      }
      return ans;
    }
    
    void leave(int pos) {
      int start=-1, end=n;
      set<s>::iterator a, b;
      for(auto p=st.begin(); p!=st.end(); ++p){
        if(p->start==pos){
          end=p->end;
          a=p;
        }if(p->end==pos){
          start=p->start;
          b=p;
        }
      }
      if(pos!=n-1) st.erase(a);
      if(pos!=0) st.erase(b);
      st.emplace(start, end);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */