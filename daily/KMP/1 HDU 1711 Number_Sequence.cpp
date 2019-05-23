#include<cstdio>
using namespace std;
const int maxn = 1e6+9;
const int maxm = 1e4+9;
int p[maxm], a[maxn], b[maxm];
void solve(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; ++i){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=m; ++i){
		scanf("%d", &b[i]);
	}
	int j=0;
	for(int i=2; i<=m; ++i){
		while(j>0&&b[j+1]!=b[i]){
			j=p[j];
		}
		if(b[j+1]==b[i]){
			++j;
		}
		p[i]=j;
	}
	j=0;
	for(int i=1; i<=n; ++i){
		while(j>0&&b[j+1]!=a[i]){
			j=p[j];
		}
		if(b[j+1]==a[i]){
			++j;
		}
		if(j==m){
			printf("%d\n", i-m+1);
			return ;
		}
	}
	puts("-1");
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		solve();
	}
	return 0;
}
