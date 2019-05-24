#include<cstdio>
using namespace std;
int n;
void solve(){
	long long ans=0;
	while(n--){
		long long l, r;
		scanf("%lld%lld", &l, &r);
		if((r-l+1)*(r-l+1)>ans){
			ans=(r-l+1)*(r-l+1);
		}
	}
	printf("%lld\n", ans); 
}
int main(){
	while(scanf("%d", &n)!=EOF){
		solve();
	}
	return 0;
}
