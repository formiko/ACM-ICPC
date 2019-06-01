#include<cstdio>
#include<vector>
using namespace std;
#define ll long long
const ll inf = 1e15;
ll V;
vector<ll>p;
vector<ll>cnt;
vector<ll>d[29];
ll ans=inf;
void dfs(int cur, ll a, ll b){
	if(cur==p.size()){
		ll c=V/a/b;
		ans=min(ans, 2*(a*b+a*c+b*c));
		return ;	
	}
	for(int i=0; i<=cnt[cur]; ++i){
		a*=d[p[cur]][i];
		for(int j=0; j<=cnt[cur]-i; ++j){
			b*=d[p[cur]][j];
			dfs(cur+1, a, b);
			b/=d[p[cur]][j];
		}
		a/=d[p[cur]][i];
	}
}
int main(){
	scanf("%lld", &V);
	ll old_V=V;
	for(int i=2; i*i<=V; ++i){
		if(V%i==0){
			p.push_back(i);
			int t_cnt=0;
			while(V%i==0){
				++t_cnt;
				V/=i;
			}
			cnt.push_back(t_cnt);
		}
	}
	V=old_V;
	for(int i=0; i<p.size(); ++i){
		d[p[i]].push_back(1);
		for(int j=1; j<=cnt[i]; ++j){
			d[p[i]].push_back(d[p[i]][j-1]*p[i]);
		}
	}
	dfs(0, 1, 1);
	printf("%lld\n", ans);
	return 0;
}
