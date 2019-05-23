#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1e6+9;
char a[maxn];
int p[maxn];
void work_p(int n){
	int j=0;
	for(int i=2; i<=n; ++i){
		while(j>0&&a[j+1]!=a[i]){
			j=p[j];
		}
		if(a[j+1]==a[i]){
			++j;
		}
		p[i]=j;
	}
}
int main(){
	int n, ca=1;
	while(scanf("%d", &n), n){
		scanf("%s", a+1);
		printf("Test case #%d\n", ca++);
		work_p(n);
		for(int i=2; i<=n; ++i){
			if(p[i]&&i-p[i]&&(i%(i-p[i])==0)){
				printf("%d %d\n", i, i/(i-p[i]));
			}
		}
		puts("");
	}
	return 0;
}
