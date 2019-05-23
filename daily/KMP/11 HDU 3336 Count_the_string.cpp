#include<cstdio>
using namespace std;
const int maxn = 2e5+9;
const int mod = 10007;
char a[maxn];
int p[maxn], cnt[maxn];
void solve(){
	int n, j=0, ans=1;
	scanf("%d%s", &n, a+1);
	cnt[1]=1;
	for(int i=2; i<=n; ++i){
		while(j>0&&a[j+1]!=a[i]){
			j=p[j];
		}
		if(a[j+1]==a[i]){
			++j;
		}
		p[i]=j;
		cnt[i]=cnt[p[i]]+1;
		ans=(ans+cnt[i])%mod;
	}
	printf("%d\n", ans);
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		solve();
	}	
	return 0;
}
