#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long
ll gcd(ll a, ll b){
	return b?gcd(b, a%b):a;
}
ll my_max(ll a, ll b){
	return a>b?a:b;
}
ll ans, n, c;
void work(int d){
	if(c%d){
		return ;
	}
	ll cd=c/d;
	for(ll j=1; j*j<=cd; ++j){
		if(cd%j){
			continue;
		}
		if(gcd(j, cd/j)!=1){
			continue;
		}
		if(j*d>n||cd/j*d>n){
			continue;
		}
		ans=my_max(ans, c*d);
		return ;
	}	
}
void solve(){
	ans=-1;
	scanf("%lld%lld", &n, &c);
	for(int i=1; i*i<=c; ++i){
		if(c%i==0){
			work(i);
			work(c/i);
		}
	}	
	printf("%lld\n", ans);
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		solve();
	}
	return 0;
}