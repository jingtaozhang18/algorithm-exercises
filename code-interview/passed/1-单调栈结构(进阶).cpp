#include<iostream>
#include<stack>
using namespace std;
int mem[1000000];
int ans[1000000][2];
int N;
void process(bool flag){
    stack<int> sta;
    int i,index;
    index=flag?0:1;
    for(flag?i=0:i=N-1;flag?i<N:i>-1;flag?++i:--i){
        while(!sta.empty()&&mem[sta.top()]>=mem[i]) sta.pop();
        if(sta.empty())ans[i][index]=-1;
        else ans[i][index]=sta.top();
        sta.push(i);
    }
}
int main(void){
    int i;
    scanf("%d",&N);
    for(i=0;i<N;++i) scanf("%d", &mem[i]);
    process(true);
    process(false);
    for(i=0;i<N;++i){
        printf("%d %d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}