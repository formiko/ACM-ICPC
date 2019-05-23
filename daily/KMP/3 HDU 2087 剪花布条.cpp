#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e3+9;
char a[maxn], b[maxn];
int p[maxn];
void kmp(){
	int n, m, j, ans=0;
	a[0]=b[0]='*';
	n=strlen(a)-1;
	m=strlen(b)-1;
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
			j=0;
			++ans;
		}
	}
	printf("%d\n", ans);
}
int main(){
	while(scanf("%s", a+1)){
		if('#'==a[1]&&'\0'==a[2]){
			break;
		}
		scanf("%s", b+1);
		kmp();
	}
	return 0;
}
