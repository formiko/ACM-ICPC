#include<cstdio>
using namespace std;
const int maxn = 1e5+9;
int n, a[maxn];
bool w(int pos, int nx, int dx, int ny, int dy){
	if(pos>n){
		return true;
	}
	if(a[pos]==nx){
		if(w(pos+1, nx+dx, dx, ny, dy)){
			return true;
		}	
	}
	if(a[pos]==ny){
		if(w(pos+1, nx, dx, ny+dy, dy)){
			return true;
		}
	}
	return false;
} 
void yes(){
	puts("YES");
}
bool sol(int pos, int nx, int dx, int y1){
	for(int i=pos; i<=n; ++i){
		if(w(i, nx, dx, a[i], a[i]-y1)){
			return true;
		}
		if(a[i]!=nx){
			break;
		}
		nx+=dx;
	}
	return false;
}
void solve(){
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf("%d", &a[i]);
	}
	if(n<=4){
		yes();
		return ;
	}
	bool flag=true;
	for(int i=2; i<=n; ++i){
		if(a[i]-a[i-1]!=a[2]-a[1]){
			flag=false;
			break;
		}
	}
	if(flag){
		yes();
		return ;
	}
	for(int k=2; k<n; ++k){
		if(a[k]-a[k-1]!=a[2]-a[1]){
			break;
		}
		if(sol(k+2, a[k]+a[k]-a[k-1], a[k]-a[k-1], a[k+1])){
			yes();
			return ;
		}
	}
	if(sol(4, a[3]+a[3]-a[1], a[3]-a[1], a[2])){
		yes();
		return ;
	}
	if(sol(4, a[3]+a[3]-a[2], a[3]-a[2], a[1])){
		yes();
		return ;
	}
	puts("NO");
	return ;
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		solve();
	} 
	return 0;
}