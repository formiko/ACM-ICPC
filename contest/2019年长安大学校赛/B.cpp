#include<cstdio>
using namespace std;
int a[109];
void solve(){
	int n;
	scanf("%d", &n);
	int ans=0;
	for(int i=0; i<10; ++i){
		for(int j=1; j<=n; ++j){
			if(j&(1<<i)){
				++ans;
				break;
			}
		}
	}
	printf("%d\n", ans);
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		solve();
	}
	return 0;
}