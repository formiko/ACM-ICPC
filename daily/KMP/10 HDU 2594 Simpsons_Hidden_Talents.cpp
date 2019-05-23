#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 5e4+9;
int p[maxn];
char a[maxn], b[maxn];
void solve(){
	a[0]=b[0]='*';
	int j=0, m=strlen(b)-1, n=strlen(a)-1;
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
	int ans=0;
	for(int i=1; i<=n; ++i){
		while(j>0&&b[j+1]!=a[i]){
			j=p[j];
		}
		if(b[j+1]==a[i]){
			++j;
		}
		if(j==m&&i!=n){
			j=p[j];
		}
	}
	ans=j;
	for(int i=0; i<ans; ++i){
		putchar(b[i+1]);
	}
	ans?putchar(' '):0;
	printf("%d\n", ans);
}
int main(){
	while(scanf("%s%s", b+1, a+1)!=EOF){
		solve();
	}
	return 0;
}
