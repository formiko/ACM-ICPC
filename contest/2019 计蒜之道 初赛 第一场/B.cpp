#include<cstdio>
#include<vector>
using namespace std;
#define ll long long
const int maxn = 59;
const int mod = 1e9+7;
vector<int>e[maxn];
int w[maxn][maxn];
ll ans[maxn][maxn];
int n, m;
int gcd(int a, int b){
	if(0==b){
		return a;
	}
	return gcd(b, a%b);
}
bool vis[maxn];
void dfs(int fa, int cur){
	vis[cur]=true;
	bool is_leaf=true;
	for(int i=0; i<e[cur].size(); ++i){
		int ne=e[cur][i];
		if(vis[ne]){
			continue;
		}
		is_leaf=false;
		dfs(cur, ne);
	}
	if(is_leaf){
		for(int i=1; i<=m; ++i){
			ans[cur][i]=1;
		}
		return ;

	}
	for(int i=1; i<=m; ++i){
		ans[cur][i]=1;
		for(int j=0; j<e[cur].size(); ++j){
			int ne=e[cur][j];
			if(ne==fa){
				continue;
			}
			ll sum=0;
			for(int k=1; k<=m; ++k){
				if(gcd(i, k)==w[cur][ne]){
					continue; 
				}
				sum+=ans[ne][k];
				sum%=mod;
			}
			ans[cur][i]*=sum;
			ans[cur][i]%=mod;
		}
	}

}
int main(){
	scanf("%d%d", &n, &m);
	for(int i=1; i<n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
		scanf("%d", &w[u][v]);
		w[v][u]=w[u][v];
	}
	dfs(-1, 1);
	ll  last_ans=0;
	for(int i=1; i<=m; ++i){
		last_ans+=ans[1][i];
		last_ans%=mod;
	}
	printf("%lld\n", last_ans);
	return 0;
}
