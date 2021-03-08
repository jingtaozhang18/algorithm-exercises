#include<bits/stdc++.h>
using namespace std;

// 有n张牌，从小到大排序之后，以第一张为基准找缺失的第k张牌
// 测试用例 
// 3
// 5 1
// 3 4 6 8 9
// 5 2
// 9 3 4 6 8
// 4 3
// 4 7 9 10
// ans
// 5
// 7
// 8

long long arr[100008];
void jgo(long long n, long long k){
    long long a = arr[n-1]-(arr[0]+n)+1; // 范围内缺失的数字
    if(k>a) {
        printf("%lld", arr[n-1]+k-a);
    }else{ // 在其中
        long long left=0, right=n-1, mid;
        while(left+1<right){
            mid=left+(right-left)/2;
        	// 下面的式子在考试的时候出错了，错写成了 a = arr[mid]-(arr[0]+mid-left);
            a = arr[mid]-(arr[left]+mid-left);  // [left, mid]包含的缺失数量
            if(a>=k){
                right=mid;
            }else{
                left=mid;
                k-=a;
            }
        }
        printf("%lld", arr[left]+k);
    }
}
int main(void){
    ios_base::sync_with_stdio(false);
    long long T;
    long long n, i, j;
    long long k;
    scanf("%lld", &T);
    while(T--){
        scanf("%lld%lld", &n, &k);
        for(i=0;i<n;++i) scanf("%lld", &arr[i]);
        sort(arr, arr+n);
        jgo(n, k);
        if(T) printf("\n");
    }
    return 0;
}