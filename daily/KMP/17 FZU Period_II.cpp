#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn = 1e6+9;
int p[maxn];
char b[maxn];
queue<int>ans;
void solve(int ca, int T){
	scanf("%s", b+1);
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
	int i=m;
	while(p[i]){
		ans.push(m-p[i]);
		i=p[i];
	}
	printf("Case #%d: %d\n", ca, ans.size()+1);
	while(!ans.empty()){
		printf("%d ", ans.front());
		ans.pop();
	}
	printf("%d\n", m);
}
int main(){
	int T;
	scanf("%d", &T);
	for(int i=1; i<=T; ++i){
		solve(i, T);
	}
	return 0;
}
