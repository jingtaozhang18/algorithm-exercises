#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int mem[2001][2001]; // 大小设置错之后，访问的内存出现未知错误
int tmp[2001][2];
int N,M;
stack<vector<int>> sta;

int calc(int i){ // 计算第i行为底的时候，最大的面积
  int j;
  for(j=1;j<=M;++j){
    while(!sta.empty()&&mem[i][sta.top().front()]>mem[i][j]){ // 弹出结算
      vector<int> popIndexs=sta.top();
      sta.pop();
      int leftindex=sta.empty()?0:sta.top().back();
      for(auto k:popIndexs){
        tmp[k][0]=leftindex;
        tmp[k][1]=j;
      }
    }
    if(!sta.empty() && mem[i][sta.top().front()]==mem[i][j])
      sta.top().push_back(j);
    else{
      sta.push(vector<int>(1,j));
    }

  }
  while(!sta.empty()){ // 弹出结算
    vector<int> popIndexs=sta.top();
    sta.pop();
    int leftindex=sta.empty()?0:sta.top().back();
    for(auto k:popIndexs){
      tmp[k][0]=leftindex;
      tmp[k][1]=M+1; // 右边界
    }
  }
  // 计算最大面积
  int ans=0;
  for(j=1;j<=M;++j){
    ans=max(ans,(tmp[j][1]-tmp[j][0]-1)*mem[i][j]);
  }
  return ans;
};
int main(void){
  int i,j,ans=0;
  cin>>N>>M;
  for(i=1;i<=N;++i){
    for(j=1;j<=M;++j){
      scanf("%d",&mem[i][j]);
      mem[i][j]=mem[i][j]?mem[i-1][j]+1:0;
    }
  }
  for(i=1;i<=N;++i){
    ans=max(ans,calc(i));
  }
  cout<<ans<<endl;
  return 0;
}