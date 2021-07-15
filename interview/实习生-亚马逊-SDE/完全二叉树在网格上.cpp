#include<math.h>
using namespace std;

// 给定一个完全二叉树，放在网格纸上，判断一个给定的坐标是否是节点位置
bool calc(int n, int x, int y){
    if(n>=1&&x>=0&&y>=0); else return false;
    if(y>=n) return false;
    int i=n-1; long long gs=1;
    while(i>y){
        gs=2*gs+1;
    }
    long long size = math.pow(2, i);
    if((long long)x/(gs+1)>=size) return false;
    return x-x/(gs+1)*(gs+1)==gs/2;
}