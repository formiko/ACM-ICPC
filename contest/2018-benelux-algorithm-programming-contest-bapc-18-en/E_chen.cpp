#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
const ll mod = 1e9+9;
const int maxn = 5009;
int n, a[maxn];
ll inv[maxn];
int rt[maxn];	//repeat times
ll perm[maxn][maxn], p[maxn];
ll qpow(ll a, ll b){
	ll re=1;
	while(b){
		if(b&1)	re=re*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return re;
}
void init(){
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a+1, a+1+n);
	for(int i=1; i<=n; ++i){
		inv[i]=qpow(i, mod-2);
//		printf("%d ", inv[i]);
	}
	for(int i=1; i<=n; ++i){
		perm[i][i]=1;
		perm[i+1][i]=1;
		rt[i]=1;
		for(int j=i+1; j<=n; ++j){
			rt[j]=a[j]==a[j-1]?rt[j-1]+1:1;
			perm[i][j]=((perm[i][j-1]*(j-i+1)%mod)*inv[rt[j]])%mod;
//			printf("*%d %d %d %lld %lld\n", rt[j], i, j, perm[i][j], perm[i][j-1]);
		}
	}
}
void solve(){
	p[0]=1;
	p[1]=0;
	for(int i=2; i<=n; ++i){
		p[i]=perm[1][i];
		for(int j=1; j<=i; ++j){
			p[i]=((p[i]-p[j-1]*perm[j+1][i]%mod)%mod+mod)%mod;
		}
//		printf("%d %lld\n", i, p[i]);
	}
	printf("%lld\n", p[n]);
}
int main(){
	init();
	solve();
	return 0;
}
