#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<map>
#include<utility>
using namespace std;
#define mp make_pair
#define X first
#define Y second
const int N=1008;
map<pair<int,int>,int>f;
int n,a[N],b[N],s;
int work(int x,int y)
{
	if(f.find(mp(x,y))!=f.end())return f[mp(x,y)];
	if(x>n){return f[mp(x,y)]=(y==0);}
	if((y>0&&y>b[x])||(y<0&&-y>b[x]))return 0; // 剪枝
	f[mp(x,y)]=work(x+1,y+a[x])+work(x+1,y-a[x]);
	return f[mp(x,y)];
}
int main(void)
{
	int i;
	scanf("%d%d",&n,&s);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=n;i>=1;i--)b[i]=b[i+1]+a[i];
	cout<<work(1,s);
	return 0;
}