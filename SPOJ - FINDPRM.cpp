//cin cout gives TLE

#include<bits/stdc++.h>
using namespace std;
int prime1[10000010];
int prime[10000010];
void sieve1()
{
	for(int i=1;i<=10000010;i++)
	prime1[i]=1;
	
	prime1[1]=0;
	for(int i=2;i*i<=10000010;i++)
	if(prime1[i]==1)
	for(int j=i*i;j<=10000010;j=j+i)
	prime1[j]=0;
}
void sieve2()
{
	for(int i=2;i<=10000010;i++)
	{
		prime[i]=prime[i-1];
		if(i%2==0 && prime1[i/2]==1)
		prime[i]=prime[i]-1;
		if(prime1[i]==1)
		prime[i]=prime[i]+1;
	}
}
int main()
{
	int t,n,i;
	sieve1();
	sieve2();
    scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",prime[n]);
	}
}
