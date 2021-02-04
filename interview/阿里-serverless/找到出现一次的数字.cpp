#include<bits/stdc++.h>
using namespace std;

// 出现次数为偶数的数都是挨在一起的
// 1 3 3 2 2 
// 5 5 3 3 1 2 2
// 1 5 5 3 3 2 2
// a[:2n] a[i]==a[i+1] i是偶数
// a[:2n+1] j 


// 从数组长度判断是否存在只出现了一次的数
int func(vector<int>& arr, int left, int right){ // find arr[left:right] 
	if((right-left+1)%2==0) return -1; // 偶数长度下不存在
  int mid=left+(right-left)/2, m=mid, n=mid;
	while(m>=left&&arr[m]==arr[mid]) --m;
  while(n<=right&&arr[n]==arr[mid]) ++n;
  if((n-m-1)%2==1) return arr[mid];
  if((m-left+1)%2==1) return func(arr, left, m);
	if((right-n+1)%2==1) return func(arr, n, right);
  return -1; // not found;
}

// 找出出现次数为1(或者奇数次)的数
int enter(vector<int>& arr){
  return func(arr, 0, arr.size()-1);
}

int main(){
  vector<int> a{};
  cout<<enter(a)<<endl;
  return 0;
}