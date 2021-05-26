// https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cca3
#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    int N, K, i, j, k;
    string str;
    for(j=0;j<T;++j){
        cin>>N>>K>>str;    
        for(i=k=0;i<N-i;++i) k+=(str[i]==str[N-i-1]?0:1);
        printf("Case #%d: %d\n", j+1, abs(k-K));
    }
    return 0;
}