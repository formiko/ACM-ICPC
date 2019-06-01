#include<cstdio>
using namespace std;
bool a[19][39];
char s[99];
int e[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int last[19][39];
int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		int m, d;
		scanf("%s", s);
		scanf("%d-%d", &m, &d);
		a[m][d]=true;
	}
	
	int cnt=0, ans=0, ans_m, ans_d;
	for(int m=10; m<=12; ++m){
		for(int d=(10==m)?28:1; d<=e[m]; ++d){
			last[m][d]=++cnt;
		}
	}
	for(int m=1; m<=10; ++m){
		for(int d=1; d<=(10==m?27:e[m]); ++d){
			last[m][d]=++cnt;
		}
	}
//	for(int m=1; m<=12; ++m){
//		for(int d=1; d<=e[m]; ++d){
//			printf("%d %d %d\n", m, d, last[m][d]);
//		}
//	}
	cnt=0;
	for(int k=0; k<3; ++k){
		for(int m=1; m<=12; ++m){
			for(int d=1; d<=e[m]; ++d){
				if(a[m][d]){
					cnt=0;
				}
				else{
					++cnt;
					if(cnt>ans||(cnt==ans&&last[ans_m][ans_d]>last[m][d])){
						ans=cnt;
						ans_m=m;
						ans_d=d;
					}
				}
			}
		}
	}
	printf("%02d-%02d\n", ans_m, ans_d);
	return 0;
}
