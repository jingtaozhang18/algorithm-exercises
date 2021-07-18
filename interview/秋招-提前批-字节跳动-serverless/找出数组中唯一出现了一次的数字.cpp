// 只有一个数字x出现了一次，其他所有数字出现了3次，找到数字x, 所有数字都是正整数
#include <bits/stdc++.h>
using namespace std;

int calc(vector<int>& arr){
    int a=0, b=0, x, y;
    for(auto &e:arr){
        x=a, y=b;
        a=(~x&~y&e)|(x&~y&~e);
        b=(~y&x&e)|(y&~x&~e);
        cout<<bitset<4>(b)<<" "<<bitset<4>(a)<<endl;
    }
    return a;
}

int main(void){
    vector<int>arr{4,1,1,8,4,8,4,3,1,8};
    cout<<calc(arr)<<endl;
    return 0;
}

// b[0] a[0] e[0] => b a
// 0    0    0       0 0
// 0    0    1       0 1
// 0    1    0       0 1
// 0    1    1       1 0
// 1    0    0       1 0
// 1    0    1       0 0
