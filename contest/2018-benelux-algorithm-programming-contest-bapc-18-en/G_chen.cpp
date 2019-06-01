#include<cstdio>
using namespace std;
const int maxn = 1e5+9;
char ts[maxn];
int s[maxn], sum[3][maxn], num[3];
int min(int a, int b){
	return a<b?a:b;
}
int main(){
	int n, ans;
	scanf("%d", &n);
	ans=n;
	scanf("%s", ts+1);
	for(int i=1; i<=n; ++i){
		s[i]=ts[i]-'A';
	}
	for(int i=1; i<=n; ++i){
		for(int j=0; j<3; ++j){
			sum[j][i]=sum[j][i-1]+(j==s[i]);
		}
	}
//	for(int i=1; i<=n; ++i){
//		printf("*%d ", s[i]);
//	}
	for(int i=0; i<3; ++i){
		num[i]=sum[i][n];
	}
	for(int i=0; i<=num[0]; ++i){
		int x, y, z;
		x=i;
		y=i+num[1];
		z=y+num[2];
		ans=min(ans, x-sum[0][x]+num[0]-x-(sum[0][n]-sum[0][n-(num[0]-x)])+num[1]-(sum[1][y]-sum[1][x])+num[2]-(sum[2][z]-sum[2][y]));
	}
	for(int i=0; i<=num[0]; ++i){
		int x, y, z;
		x=i;
		y=i+num[2];
		z=y+num[1];
		ans=min(ans, x-sum[0][x]+num[0]-x-(sum[0][n]-sum[0][n-(num[0]-x)])+num[2]-(sum[2][y]-sum[2][x])+num[1]-(sum[1][z]-sum[1][y]));
	}
	for(int i=0; i<=num[1]; ++i){
		int x, y, z;
		x=i;
		y=i+num[0];
		z=y+num[2];
		ans=min(ans, x-sum[1][x]+num[1]-x-(sum[1][n]-sum[1][n-(num[1]-x)])+num[0]-(sum[0][y]-sum[0][x])+num[2]-(sum[2][z]-sum[2][y]));
	}
	for(int i=0; i<=num[1]; ++i){
		int x, y, z;
		x=i;
		y=i+num[2];
		z=y+num[0];
		ans=min(ans, x-sum[1][x]+num[1]-x-(sum[1][n]-sum[1][n-(num[1]-x)])+num[2]-(sum[2][y]-sum[2][x])+num[0]-(sum[0][z]-sum[0][y]));
	}
	for(int i=0; i<=num[2]; ++i){
		int x, y, z;
		x=i;
		y=i+num[0];
		z=y+num[1];
		ans=min(ans, x-sum[2][x]+num[2]-x-(sum[2][n]-sum[2][n-(num[2]-x)])+num[0]-(sum[0][y]-sum[0][x])+num[1]-(sum[1][z]-sum[1][y]));
	}
	for(int i=0; i<=num[2]; ++i){
		int x, y, z;
		x=i;
		y=i+num[1];
		z=y+num[0];
		ans=min(ans, x-sum[2][x]+num[2]-x-(sum[2][n]-sum[2][n-(num[2]-x)])+num[1]-(sum[1][y]-sum[1][x])+num[0]-(sum[0][z]-sum[0][y]));
	}
	printf("%d\n", ans);
	return 0;
}
