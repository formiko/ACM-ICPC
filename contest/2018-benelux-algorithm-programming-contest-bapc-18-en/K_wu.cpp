#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
vector<int> G[maxn];
int leaf[maxn];
int cnt = 0;
bool vis[maxn];

void dfs(int u, int fa) {
	if(G[u].size() == 1) leaf[cnt++] = u;
	for(int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if(v != fa) dfs(v, u);
	}
}
int main() {
//	freopen("data.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(m, -1);
//	printf("--%d--\n", cnt);
//	for(int i = 0; i < cnt; i++) printf("%d ", leaf[i]);
//	printf("\n");
	if(cnt&1) {
			printf("%d\n", (cnt+1)/2);
			for(int i = 0; i < cnt/2; i++) printf("%d %d\n", leaf[i], leaf[i+(cnt/2)]);
			printf("%d %d\n", leaf[cnt-1], n-1-leaf[cnt-1]);
	} else {
		printf("%d\n", cnt/2);
		for(int i = 0; i < cnt/2; i++) printf("%d %d\n", leaf[i], leaf[i+(cnt/2)]);
	}
	return 0;
}
