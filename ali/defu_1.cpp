#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
const int N=20000008;
int a[10],f[N];
int minx(int x,int y){if(x<y)y=x;return y;}
int id(void)
{
	int e=0;for(int i=1;i<=10;i++)e=e*5+a[i];
	return e;
}
int dfs(int x)
{
	int idp=id();
	if(x==11)return 0;
	if(f[idp]>=0)return f[idp];
	int y=99999999;
	if(x<=8&&a[x]>=2&&a[x+1]>=2&&a[x+2]>=2)
	{
		a[x]-=2;a[x+1]-=2;a[x+2]-=2;
		y=minx(y,1+dfs(x+(a[x]==0)));
		a[x]+=2;a[x+1]+=2;a[x+2]+=2;
	}
	if(x<=6&&a[x]&&a[x+1]&&a[x+2]&&a[x+3]&&a[x+4])
	{
		a[x]--;a[x+1]--;a[x+2]--;a[x+3]--;a[x+4]--;
		y=minx(y,1+dfs(x+(a[x]==0)));
		a[x]++;a[x+1]++;a[x+2]++;a[x+3]++;a[x+4]++;
	}
	if(x<=10&&a[x]>=2)
	{
		a[x]-=2;
		y=minx(y,1+dfs(x+(a[x]==0)));
		a[x]+=2;
	}
	int k=a[x];
	a[x]=0;
	y=minx(y,k+dfs(x+1));
	a[x]=k;
	return f[idp]=y;
}
int main(void)
{
	int i;
	for(i=1;i<=10;i++)cin>>a[i];
	memset(f,-1,sizeof(f));
	cout<<dfs(1);
	return 0;
}