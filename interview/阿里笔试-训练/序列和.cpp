// https://www.nowcoder.com/practice/46eb436eb6564a62b9f972160e1699c9?tab=answerKey
#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n, l, i, left=0, right=0, acc=0, al=-1, ar=INT_MAX-10; // 错误点： 必须从0开始，因为有最短长度限制
                                                               // 错误点： ar不要随便设置成最大值，容易发生越界
    cin>>n>>l;
    while(right<=n){
        acc+=right;
        ++right;
        while(acc>n) acc-=left++;
        if(acc==n&&right-left>=l){
            if(right-left<ar-al) {
                if(left==0 &&right-left>l) al=left+1;
                else al=left;
                ar=right;
            }
        }
    }
    if(al==-1||ar-al>100) cout<<"No";
    else {
        for(i=al;i<ar-1;++i){
            cout<<i<<" ";
        }
        cout<<ar-1;
    }
    return 0;
}