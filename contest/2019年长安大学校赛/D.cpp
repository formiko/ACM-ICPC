#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 1e3+9;
int n, m;
vector<int>e[maxn];
int f[maxn], a[maxn][maxn];
bool b[maxn];
int dx[]={0, 0, -1, 1};
int dy[]={-1, 1, 0, 0};
bool find(int u){
	for(int i=0; i<e[u].size(); ++i){
		int v=e[u][i];
		if(b[v]){
			continue;
		} 
		b[v]=true;
		if(-1==f[v]||find(f[v])){
			f[v]=u;
			return true;
		}
	}
	return false;
}
bool is_in(int x, int y){
	return 0<=x&&x<n&&0<=y&&y<m;
}
bool ok(int mid, int need){
	for(int i=0; i<n*m; ++i){
		e[i].clear();
		f[i]=-1;
	}
	int ans=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(a[i][j]>=mid){
				++ans;
			}
			if(a[i][j]>=mid&&(i+j)%2){
				int cd=i*m+j;
				for(int k=0; k<4; ++k){
					int nx=i+dx[k], ny=j+dy[k];
					if(is_in(nx, ny)&&a[nx][ny]>=mid){
						e[cd].push_back(nx*m+ny);
					}
				}
			}
		}
	}
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(a[i][j]>=mid&&(i+j)%2){
				for(int k=0; k<n*m; ++k){
					b[k]=false;
				}
				if(find(i*m+j)){
					--ans;
				}
			}
		}
	}
	return ans>=need;
}
void solve(){
	int k;
	scanf("%d%d%d", &n, &m, &k);
	int L=1009, R=0;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			scanf("%d", &a[i][j]);
			L=min(L, a[i][j]);
			R=max(R, a[i][j]);
		}
	}
	while(L<R){
		int mid=(L+R+1)/2;
		if(ok(mid, k)){
			L=mid;
		}
		else{
			R=mid-1;
		}
	}
	printf("%d\n", L);
	
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		solve();
	}
	return 0;
}