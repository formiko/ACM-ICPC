#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int maxn = 4e5+9;
char b[maxn];
int p[maxn];
stack<int>ans;
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
	ans.push(m);
	while(p[m]){
		m=p[m];
		ans.push(m);
	}
	printf("%d", ans.top());
	ans.pop();
	while(!ans.empty()){
		printf(" %d", ans.top());
		ans.pop();
	}
	putchar('\n');
}
int main(){
	while(scanf("%s", b+1)!=EOF){
		solve();
	}
	return 0;
}
