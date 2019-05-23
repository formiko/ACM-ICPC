#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
const ll MOD=1e8+7;
ll n,m,k;
LL quickPower(LL a, LL b)
{
    LL ans = 1;
    a %= MOD;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % MOD;
        }
        b >>= 1;
        a = a * a % MOD;
    }
    return ans;
}
  
LL c(LL n, LL m)
{
    if (m > n)
    {
        return 0;
    }
    LL ans = 1;
    for (int i = 1; i <= m; i++)
    {
        LL a = (n + i - m) % MOD;
        LL b = i % MOD;
        ans = ans * (a * quickPower(b, MOD - 2) % MOD) % MOD;
    }
    return ans;
}
  
LL lucas(LL n, LL m)
{
    if (m == 0)
    {
        return 1;
    }
    return c(n % MOD, m % MOD) * lucas(n / MOD, m / MOD) % MOD;
}
ll t1[100010];
ll t2[100010];
ll inv[100011];
void Inv()
{
    for(int i=0;i<=100010;i++)
    {
        inv[i]=quickPower(i,MOD-2);
    }
}
void Init()
{
    t1[0]=1;
    for(int i=1;i<=m;i++)
    {
        t1[i]=t1[i-1]*(m-i+1)%MOD*inv[i]%MOD;
    }
    t2[m-1]=1;
    for(int i=m;i<n;i++)
    {
        t2[i]=t2[i-1]*i%MOD*inv[i-m+1]%MOD;
    }
}
int main()
{
    int t;
    Inv();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld%lld",&n,&m,&k);
        Init();
        int len=min(m,(n-m)/k);
        ll sum=0;
        ll tem;
        for(int i=0;i<=len;i++)
        {
            int l=i&1?-1:1;
            sum=(sum+t1[i]*t2[n-i*k-1]*l)%MOD;
        }
        while(sum<0)
        sum+=MOD;
        printf("%lld\n",sum);
    }
    return 0;
 }