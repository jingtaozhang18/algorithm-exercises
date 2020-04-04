#include<iostream>
#include<stack>
using namespace std;
int mem[1000000];
int ans[1000000][2];
int N;
void process(bool flag){
    stack<int> sta;
    int i,index,step;
    index=flag?0:1;
    i=flag?0:N-1;
    for(flag?i=0:i=N-1;flag?i<N:i>-1;flag?++i:--i){
        while(!sta.empty()&&mem[sta.top()]>mem[i]) sta.pop();
        if(sta.empty())ans[i][index]=-1;
        else ans[i][index]=sta.top();
        sta.push(i);
    }
}
int main(void){
    int i;
    cin>>N;
    for(i=0;i<N;++i) cin>>mem[i];
    process(true);
    process(false);
    for(i=0;i<N;++i){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}