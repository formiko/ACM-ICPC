#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6+9;
char b[maxn];
int p[maxn];
void solve(){
	b[0]='*';
	int j=0, m=strlen(b)-1;
	for(int i=2; i<=m; ++i){
		while(j>0&&b[j+1]!=b[i]){
			j=p[j];
		}
		if(b[j+1]==b[i]){
			++j;
		}
		p[i]=j;
	}	
	printf("%d\n", m%(m-p[m])?1:m/(m-p[m]));
}
int main(){
	while(scanf("%s", b+1), !('.'==b[1]&&'\0'==b[2])){
		solve();
	}
	return 0;
}
