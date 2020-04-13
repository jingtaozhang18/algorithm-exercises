#include<cstdio>
#include<algorithm>
using namespace std;

int ta [500002][2];
void create_tree(int ma[2002][2], int count){
  int f;
  while(count--){
    scanf("%d",&f);
    scanf("%d%d",&ma[f][0],&ma[f][1]);
  }
}

int calc(int root,bool &ans){ // 计算树高
  if(!root) return 0;
  int L=0,R=0,diff;
  if(ans&&ta[root][0]) L=calc(ta[root][0],ans);
  if(ans&&ta[root][1]) R=calc(ta[root][1],ans);
  diff=L-R;
  diff=diff<0?(-1*diff):diff;
  if(diff>1) ans=false;
  return max(L,R)+1;
}
int main(void){
  int ca,ra;
  bool ans=true;
  scanf("%d%d",&ca,&ra);
  create_tree(ta,ca);
  calc(ra, ans);
  if(ans) printf("true");
  else printf("false");
  return 0;
}