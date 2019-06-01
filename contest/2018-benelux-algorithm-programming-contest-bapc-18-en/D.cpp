#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int l[maxn], r[maxn], tower[maxn];
int fa[maxn];
struct node{
	int x, y, step;
};
int find(int x) {
	if(fa[x] != x) return fa[x] = find(fa[x]);
	return x;
}
int main() {
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	for(int i = 0; i < n; i++) {
		scanf("%d%d%d", &l[i], &r[i], &tower[i]);
		fa[i] = i;
	}
	node P;
	P.x = a; P.y = b; P.step = 0;
	queue<node> Q;
	Q.push(P);
	int ans = -1;
	while(!Q.empty()) {
		P = Q.front(); Q.pop();
		int sx = P.x, sy = P.y, st = P.step;
		int fx = find(sx), fy = find(sy);
		if(fx == fy) continue;
		if(tower[fx] != tower[fy]) {
			ans = st;
			break;
		}
		fa[fx] = fy;
		Q.push(node{l[sx], l[sy], st+1});
		Q.push(node{r[sx], r[sy], st+1});
	}
	if(ans == -1) printf("indistinguishable\n");
	else printf("%d\n", ans);
	return 0;
}
