#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e5+9;
char b[maxn];
int p[maxn];
void solve(){
	scanf("%s", b+1);
	b[0]='*';
	int min_circle, j=0, m=strlen(b)-1;
	for(int i=2; i<=m; ++i){
		while(j>0&&b[j+1]!=b[i]){
			j=p[j];
		}
		if(b[j+1]==b[i]){
			++j;
		}
		p[i]=j;
	}
	min_circle=m-p[m];
	if(min_circle==m){
		printf("%d\n", m);
	}
	else{
		if(m%min_circle){
			printf("%d\n", min_circle-m%min_circle);
		}
		else{
			puts("0");
		}	
	}
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		solve();
	}
	return 0;
}
