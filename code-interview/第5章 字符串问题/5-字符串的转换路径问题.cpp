#include<bits/stdc++.h>
using namespace std;

// 不考虑start出现在list中的情况
string arr[5001];
bool gra[5001][5001]; // start为与n的位置
int dis[5001]; // 每个单词到start的距离
int path[5001];

bool isNeig(int i, int j){ // 判断 arr[i]和arr[j]是否相邻
  int diff=0,k;
  for(k=0;k<arr[i].size();++k){
    if(arr[i][k]!=arr[j][k]) diff++;
  }
  return diff==1?true:false;
}

void generate_gra(int n){ // 生成图网络
  for(int i=0;i<=n;++i)
    for(int j=i+1;j<=n;++j)
      if(isNeig(i,j))
        gra[i][j]=gra[j][i]=true;
}

void bfs(int n){ // 生成每个点到start的距离
  int color[5001]; // 记录点的颜色 0 未探索，1 已发现， 2已出发
  memset(color,0,sizeof color);
  queue<int> que;
  color[0]=1;
  dis[0]=0;
  que.push(0);
  while(!que.empty()){
    int d=que.front();
    que.pop();
    for(int i=1;i<=n;++i){
      if(gra[d][i]){ // 是可达点
        if(color[i]==0){
          que.push(i);
          color[i]=1;
          dis[i]=dis[d]+1;
        }
      }
    }
    color[d]=2;
  }
}
void dfs(int cur, int deep, int n, int lp){ // 当前字符，遍历深度，目标位置
  int i, j;
  for(i=1;i<=n;++i){
    if(gra[cur][i] && dis[i]==deep){ // 连通，并且距离满足条件
      path[deep]=i;
      if(i==lp){ // 找到了一条轨迹
        for(j=0;j<deep;++j) cout<<arr[path[j]]<<" -> ";
        cout<<arr[path[j]]<<endl;
      }else{
        dfs(i,deep+1,n,lp);
      }
    }
  }
}


int main(void){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n,i,end_pos=-1;
  string start, end;
  cin>>n>>start>>end;
  arr[0]=start;
  for(i=1;i<=n;++i) cin>>arr[i];
  sort(arr+1, arr+n+1);
  for(i=1;i<=n;++i) if(arr[i]==end) end_pos=i;
  generate_gra(n);
  bfs(n);
  // 题目保证last_pos有效
  if(dis[end_pos]==0){
    cout<<"NO"<<endl;
  }else{
    cout<<"YES"<<endl;
    dfs(0,1,n,end_pos);
  }
  return 0;
}