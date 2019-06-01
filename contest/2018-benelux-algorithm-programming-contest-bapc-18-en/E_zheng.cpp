#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[10010];
ll MOD=1e9+9;
ll a[10010];
ll fac[10010];
ll feima[10010];
map<ll,int> mp;
map<ll,int> mp2;
long long powM(long long a, long long b, long long m)
{
    long long tmp = 1;
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a % m;
    }

    tmp = powM(a, b >> 1, m);
    tmp = tmp * tmp % m;

    if (b & 1)
    {
        tmp = tmp * a % m;
    }

    return tmp;
}
ll inv(ll num)
{
	return powM(num,MOD-2,MOD);
}
void init()
{
	fac[0]=1;
	for(int i=1;i<=10000;i++)
	{
		fac[i]=(fac[i-1]*i)%MOD;
		feima[i]=inv(i);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++)
	scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	p[0]=1;
	mp.clear();
	ll last=1;
	for(int i=1;i<=n;i++)
	{
		mp[a[i]]++;
		ll num1=last*i%MOD*feima[mp[a[i]]]%MOD;
		last=num1;
		ll num2=0;
		ll last2=num1;
		mp2.clear();
		map<ll,int>::iterator it;
		for(it=mp.begin();it!=mp.end();it++)
		{
			mp2[it->first]=it->second;
		}
		for(int j=1;j<=i;j++)
		{
			last2=last2%MOD*feima[i-j+1]%MOD*mp2[a[j]]%MOD;
			num2+=p[j-1]*last2%MOD;
            mp2[a[j]]--;
		}
		p[i]=num1-num2;
		while(p[i]<0)
		p[i]+=MOD;
	}
	printf("%lld\n",p[n]);
	return 0;
}
