#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6+9;
char b[maxn];
int p[maxn];
void solve(){
	b[0]='*';
	int j, m=strlen(b)-1;
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
	printf("%d\n", m-p[m]);
}
int main(){
	while(scanf("%s", b+1)!=EOF){
		solve();
	}
	return 0;
}
