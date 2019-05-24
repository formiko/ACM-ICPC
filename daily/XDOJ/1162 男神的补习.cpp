#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn = 1e6+9;
vector<int>e[maxn];
int a[maxn], b[maxn], cnt[maxn];
bool du[maxn], vis[maxn];
bool dfs(int cur, int push_down_cnt, int k){
	vis[cur]=true;
	cnt[cur]+=push_down_cnt;
	if(a[cur]+cnt[cur]*k<60){
		return false;
	}
	for(int i=0; i<e[cur].size(); ++i){
		int ne=e[cur][i];
		if(vis[ne]){
			continue;
		}
		if(!dfs(ne, cnt[cur], k)){
			return false;
		}
	}
	return true;
}
bool ok(int mid, int root, int k){
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	for(int i=1; i<=mid; ++i){
		++cnt[b[i]];
	}
	return dfs(root, 0, k);
}
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for(int i=1; i<n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		du[v]=true;
		e[u].push_back(v);
	}
	int root;
	for(int i=1; i<=n; ++i){
		if(!du[i]){
			root=i;
			break;
		}
	}
	for(int i=1; i<=n; ++i){
		scanf("%d", &a[i]);
	}
	for(int i=1; i<=m; ++i){
		scanf("%d", &b[i]);
	}
	int L=0, R=m+1;
	while(L<R){
		int mid=(L+R)/2;
		if(ok(mid, root, k)){
			R=mid;
		}
		else{
			L=mid+1;
		}
	}
	if(R==m+1){
		puts("mdzz");
	}
	else{
		printf("%d\n", R);
	}
	return 0;
}
