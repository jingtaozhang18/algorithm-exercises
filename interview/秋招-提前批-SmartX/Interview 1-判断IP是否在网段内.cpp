// 判断一个 IP 是否属于一个子网。
// 例如 192.168.67.211 属于 192.168.64.0/20。
#include<bits/stdc++.h>
using namespace std;

unsigned int jres(string &ip){
    int i, m=ip.size(), index=3;
    unsigned int val=0, ans=0;
    for(i=0;i<=m;++i){
        if(i==m||ip[i]=='.'){
            val<<=(index*8);
            ans|=val;
            val=0, --index;
        }else{
            val*=10, val+=(ip[i]-'0');
        }
    }
    return ans;
}

bool calc(string &ip, string &net, int k){
    unsigned int x=jres(ip);
    unsigned int y=jres(net);
    // unsigned int mask=0, i=31;
    // while(k--) mask|=(1<<i), --i;
    unsigned long mask=1;
    mask=~((1<<(32-k))-1);
    cout<<bitset<32>(x)<<endl;
    cout<<bitset<32>(y)<<endl;
    cout<<bitset<32>(mask)<<endl;
    return (x&mask)==(y&mask);
}

int main(void){
    string ip="192.168.67.211";
    string net="192.168.64.0";
    cout<<calc(ip, net, 30)<<endl;
    return 0;
}
