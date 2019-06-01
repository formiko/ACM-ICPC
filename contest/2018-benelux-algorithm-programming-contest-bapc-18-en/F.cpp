#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
const int maxn = 1e5+9;
const ll inf = 1e18;
ll n, m;
struct node{
	ll p, c;
	double q;
};
ll my_min(ll a, ll b){
	return a<b?a:b;
}
node a[maxn];
bool cmp(node a, node b){
	return a.q>b.q;
}
ll sump[maxn], sumc[maxn];
int main(){
	scanf("%lld%lld", &n, &m);
	for(int i=1; i<=n; ++i){
		scanf("%lld%lld", &a[i].p, &a[i].c);
		a[i].q=(double)a[i].p/(double)a[i].c;
	}
	sort(a+1, a+1+n, cmp);
	a[0]={node{0, 0, 0}};
	for(int i=1; i<=n; ++i){
		sump[i]=sump[i-1]+a[i].p;
		sumc[i]=sumc[i-1]+a[i].c;
//		printf("%lld %lld\n", sump[i], sumc[i]);
	} 
	ll ans=inf;
	for(int i=1; i<=n; ++i){
		ans=my_min(ans, (m+sumc[i])%sump[i]?(m+sumc[i])/sump[i]+1:(m+sumc[i])/sump[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
