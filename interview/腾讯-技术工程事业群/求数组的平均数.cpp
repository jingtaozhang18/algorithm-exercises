#include <iostream>
using std::cout;
using std::endl;

long get_avg(long* arr, long length){
    long MLONG_MAX = length;
    long MLONG_MIN = -(MLONG_MAX - 1);
    long ans=0;
    long mod=0;
    long x;
    for(long i=0;i<length;++i){
        ans+=arr[i]/length;
        x=arr[i]%length;
        if(x>=MLONG_MAX-mod){
            ans++;
            mod=mod-MLONG_MAX+x;
        }else if(x<=MLONG_MIN-mod){
            ans--;
            mod=x-MLONG_MIN+mod;
        }else{
            mod+=x;
        }
    }
    return ans+mod/length;
}

int main() {
    long arr[5] = {-9223372036854775807l,-9223372036854775807l,-9223372036854775807l,-9223372036854775807l,-9223372036854775807l};
    cout<<get_avg(arr, 5)<<endl;
    return 0;
}