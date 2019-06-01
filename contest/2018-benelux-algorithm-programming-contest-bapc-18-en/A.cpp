#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100010];
bool cmp(ll a,ll b)
{
	return a<b;
}
int main()
{
	int n;
	ll x;
	scanf("%d%lld",&n,&x);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	if(n==1)
	{

		printf("1\n");
	}
	else
	{
		int rec=-1;
		for(int i=n;i>=2;i--)
		{
			if(a[i]+a[i-1]<=x)
			{
				rec=i;
				break;
			}
		}
		if(rec==-1)
		{
		   printf("1\n");
		}
		else
		{
			printf("%d\n",rec);
		}
	}
}
