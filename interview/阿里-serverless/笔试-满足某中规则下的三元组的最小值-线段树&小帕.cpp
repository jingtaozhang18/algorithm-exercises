// 长度为 n (1 <= n <= 3000) 的数组 a 和 b，找到i, j, k使得 1 <= i < j < k <= n 且 a[i] <= a[j] <= a[k]，求res = min(b[i]+b[j] +b[k])
// 8
// 9 8 6  7 7 2 9 2
// 9 1 10 8 6 4 8 6
#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
const int N=100008;//assume 1<=a[i]<N
const int M=1000000008;
int pa[N],pb[N],pc[N];
struct aa{int l,r,mid,x;}a[N*4];
int minx(int x,int y){if(x<y)y=x;return y;}
int plant(int k,int left,int right,int x)
{
	a[k].l=left;a[k].r=right;a[k].mid=(left+right)>>1;a[k].x=x;
	if(left!=right)
	{
		plant(k*2,left,a[k].mid,x);
		plant(k*2+1,a[k].mid+1,right,x);
	}
	return 0;
}
int update(int k,int tar,int x)
{
	a[k].x=minx(a[k].x,x);
	if(a[k].l==a[k].r)return 0;
	if(tar<=a[k].mid)update(k*2,tar,x);
	else update(k*2+1,tar,x);
	return 0;
}
int vis(int k,int left,int right)
{
	if(a[k].l==left&&a[k].r==right)return a[k].x;
	if(right<=a[k].mid)return vis(k*2,left,right);
	else if(left>a[k].mid)return vis(k*2+1,left,right);
	return minx(vis(k*2,left,a[k].mid),vis(k*2+1,a[k].mid+1,right));
}
main(void)
{
	int i,k,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",pa+i);
	for(i=1;i<=n;i++)scanf("%d",pb+i);
	for(i=1;i<=n;i++)pc[i]=pb[i];
	plant(1,1,N,M);
	update(1,pa[1],pb[1]);
	for(i=2;i<=n;i++){pc[i]+=vis(1,1,pa[i]);update(1,pa[i],pb[i]);}
	plant(1,1,N-1,M);
	update(1,pa[n],pb[n]);
	for(i=n-1;i>=1;i--){pc[i]+=vis(1,pa[i],N-1);update(1,pa[i],pb[i]);}
	k=M;for(i=2;i<n;i++)k=minx(k,pc[i]);
	cout<<k;
	return 0;
}
/*
8
9 8 6 7 7 2 9 2
9 1 10 8 6 4 8 6
*/