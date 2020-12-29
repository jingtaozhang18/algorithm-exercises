// https://www.nowcoder.com//practice/ceeeb34083934e79ad56019cd2cef4c4?tpId=101&&tqId=33138&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N,K,i,nd=0; 
    long long x=1;
    cin>>N>>K;
    vector<int> arr(N);
    for(i=0;i<N;++i) cin>>arr[i];
    sort(arr.begin(), arr.end());
    i=0;
    while(x<=K){
        if(i<N&&arr[i]<=x) x+=arr[i++];
        else ++nd, x<<=1;
    }
    cout<<nd<<endl;
    return 0;
}