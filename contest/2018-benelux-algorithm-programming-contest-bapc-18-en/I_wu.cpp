
 #include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
typedef long long ll;
const ll inf = 1e15;

ll min(ll a, ll b) {
	if(a > b) return b;
	return a;
}
struct Edge {
	int from, to;
	ll dist;
};
struct Edge2 {
	int from, to;
	ll cap, flow;
};
struct node {
	ll d;
	int u;
	bool operator < (const node& rhs) const {
		return d > rhs.d;
	}
};
struct Dij {
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	ll d[maxn];
	
	void init(int n) {
		this->n = n;
		for(int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}
	
	void add(int from, int to, int dist) {
		edges.push_back((Edge){from, to, dist});
		m = edges.size();
		G[from].push_back(m-1);
	}
	
	void dij(int s) {
		priority_queue<node> Q;
		for(int i = 0; i < n; i++) d[i] = inf;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		Q.push((node){0, s});
		while(!Q.empty()) {
			node x = Q.top(); Q.pop();
			int u = x.u;
			if(done[u]) continue;
			done[u] = 1;
			for(int i = 0; i < G[u].size(); i++) {
				Edge& e = edges[G[u][i]];
				if(d[e.to] > d[u] + e.dist) {
					d[e.to] = d[u] + e.dist;
//					p[e.to] = G[u][i];
					Q.push((node){d[e.to], e.to});
				}
			}
		}
	} 
}solver;
struct Dinic {
	int n, m, s, t;
	vector<Edge2> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	ll d[maxn];
	int cur[maxn];
	
	void init(int n) {
		this->n = n;
		for(int i = 0; i < n; i++) G[i].clear();
		edges.clear();
	}
	void add(int from, int to, ll cap) {
		edges.push_back((Edge2){from, to, cap, 0});
		edges.push_back((Edge2){to, from, 0, 0});
		m = edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	
	bool BFS() {
		memset(vis, 0, sizeof(vis));
		queue<int> Q;
		Q.push(s);
		d[s] = 0;
		vis[s] = 1;
		while(!Q.empty()) {
			int x = Q.front(); Q.pop();
			for(int i = 0; i < G[x].size(); i++) {
				Edge2& e = edges[G[x][i]];
				if(!vis[e.to] && e.cap > e.flow) {
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}
	
	ll DFS(int x, ll a) {
		if(x == t || a == 0) return a;
		ll flow = 0, f;
		for(int& i = cur[x]; i < G[x].size(); i++) {
			Edge2& e = edges[G[x][i]];
			if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(e.cap-e.flow, a))) > 0) {
				e.flow += f;
				edges[G[x][i]^1].flow -= f;
				flow += f;
				a -= f;
				if(a == 0) break;
			}
		}
		return flow;
	}
	ll Maxflow(int s, int t) {
		this->s = s; this->t = t;
		ll flow = 0;
		while(BFS()) {
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, inf);
		}
//		printf("%d--->%dflow:: %d\n", s, t, flow);
		return flow;
	}
}Fsol;
vector<Edge> e;
vector<node> g[maxn];
vector<node> rg[maxn];

int p[maxn], she[maxn];
ll num[maxn], ttnum[maxn];
int state[1<<15]; ll tmp = 0;
bool vis[maxn];
bool ok(ll x, int n, int shelter) {
	int s = n, t = n+1;
	int pp = 0;
	
	Fsol.init(n+2+shelter); 
	memset(vis, 0, sizeof(vis));
	memset(state, -1, sizeof(state));
	for(int i = 0; i < n; i++) num[i] = ttnum[i];
	// merge
	
	for(int i = 0; i < n; i++) {
//		if(p[i]) continue;
//		printf("___%d\n", i);
		int z = 0;
		for(int j = 0; j < rg[i].size(); j++) {
			int tt = rg[i][j].u;
			if(rg[i][j].d > x) continue;
			for(int k = 0; k < shelter; k++) 
				if(she[k] == tt) {
					z |= (1<<k);
					break;
				}
		}
//		printf("%d---\n", z);
		if(state[z] == -1) state[z] = i;
		else {
			num[state[z]] += num[i];
//			printf("???%d\n", i);
			vis[i] = 1;
		}
	}
	
	for(int i = 0; i < n; i++) {
		if(vis[i] || !num[i]) continue;
//		printf("  %d   ii%d\n", i, vis[i]);
		Fsol.add(i, t, num[i]);
//		printf("%d -> %d %d\n", i, t, num[i]);
	}
//	printf("tmp:::%d\n", tmp);
	for(int i = 0; i < shelter; i++) {
		int loc = she[i];
		Fsol.add(s, n+i+2, p[loc]);
//		printf("%d -> %d %d\n", s, n+i+2, p[loc]);
		for(int j = 0; j < g[loc].size(); j++) {
//			printf("%d--%d\n", g[loc][j].d, g[loc][j].u);
			if(g[loc][j].d > x || vis[g[loc][j].u] ) continue;
			Fsol.add(n+i+2, g[loc][j].u, inf);
//			printf("%d -> %d\n", n+i+2, g[loc][j].u);
		}
	}

//	printf("%d -----> %d\n", s, t);
//	printf("==%d==\n", Fsol.Maxflow(s, t));
	return Fsol.Maxflow(s, t) == tmp;
	
	
}
int main() {
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	memset(p, 0, sizeof(p));
	for(int i = 0; i < n; i++) {
		scanf("%lld", &num[i]);
		tmp += num[i];
		ttnum[i] = num[i];
	}
	int x, y, z;
	solver.init(n);
	for(int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &z);
		x--; y--;
		solver.add(x, y, z);
		solver.add(y, x, z);
	}
	for(int i = 0; i < s; i++) {
		scanf("%d%d", &x, &z);
		x--;
		she[i] = x;
		p[x] = z;	
		solver.dij(x);
//		for(int j = 0; j < n; j++) printf("%d ", solver.d[j]);
//		printf("\n");
		for(int j = 0; j < n; j++) {
			g[x].push_back((node){solver.d[j], j});
			rg[j].push_back((node){solver.d[j], x});
		}
	}
	
	ll L = 0, R = 1e14;
	while(L < R) {
		ll mid = (L + R) >> 1;
//		printf("%lld\n", mid);
		if(ok(mid, n, s)) R = mid;
		else L = mid + 1;
	}
	printf("%lld\n", L);
	return 0;
}
