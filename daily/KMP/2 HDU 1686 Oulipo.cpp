#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6+9;
char a[maxn], b[maxn];
int p[maxn];
void kmp(){
	int j, n, m, ans=0;
	a[0]=b[0]='*';
	n=strlen(a)-1, m=strlen(b)-1;
	j=0;
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
			++ans;
			j=p[j];
		}
	}
	printf("%d\n", ans);
}
void solve(){
	scanf("%s%s", b+1, a+1);
	kmp();
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		solve();
	}
	return 0;
}
