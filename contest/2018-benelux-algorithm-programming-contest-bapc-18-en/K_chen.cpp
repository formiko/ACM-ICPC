#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 1e5+9;
vector<int>leaf;
vector<int>e[maxn];
void dfs(int cur, int fa){
	if(e[cur].size()==1){
		leaf.push_back(cur);
	}
	for(int i=0; i<e[cur].size(); ++i){
		int ne=e[cur][i];
		if(ne==fa){
			continue;
		}
		dfs(ne, cur);
	}
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i=1; i<n; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(m, -1);
	int cnt=leaf.size();
	printf("%d\n", (cnt+1)/2);
	for(int i=0; i<cnt/2; ++i){
		printf("%d %d\n", leaf[i], leaf[i+cnt/2]);
	}
	if(cnt&1){
		printf("%d %d\n", leaf[cnt-1], leaf[0]);
	}
	return 0;
}
