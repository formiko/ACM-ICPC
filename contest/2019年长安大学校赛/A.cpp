#include<cstdio>
using namespace std;
int a[101];
void solve(){
	for(int i=0; i<=100; ++i){
		a[i]=0;
	}
	for(int i=0; i<6; ++i){
		int x;
		scanf("%d", &x);
		++a[x];
	}
	for(int i=0; i<=100; ++i){
		if(1==a[i]){
			printf("%d\n", i);
			return ;
		}
	}
}
int main(){

	int T;
	scanf("%d", &T);
	while(T--){
		solve();
	}	   
	return 0;
}