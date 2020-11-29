// https://leetcode-cn.com/problems/video-stitching/
#include<bits/stdc++.h>
using namespace std;

struct cmp{
  bool operator()(const vector<int>&a, const vector<int>&b)const{
    if(a[0]==b[0]) return a[1]>b[1];
    return a[0]<b[0];
  }
} mycmp;
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
      int i, size=clips.size(),base;
      stack<vector<int>> sta;
      vector<int> tvec, pvec;
      sort(clips.begin(), clips.end(), mycmp);
      for(i=0;i<size;++i) cout<<clips[i][0]<<" "<<clips[i][1]<<endl;
      cout<<endl;
      for(base=0,i=0;i<size;++i){
        if(clips[i][0]==clips[i][1]||clips[i][1]<=base) continue; // 无意义
        if(clips[i][0]>base) return -1; // 无法组成
        base=clips[i][1];
        while(sta.size()>1){
          tvec=sta.top(); sta.pop(); pvec=sta.top(); // 尝试弹出
          if(clips[i][0]>pvec[1]){
            sta.push(tvec);
            break;
          }
        }
        sta.push(clips[i]);
        if(base>=T) return sta.size();
      }
      return -1;
    }
};