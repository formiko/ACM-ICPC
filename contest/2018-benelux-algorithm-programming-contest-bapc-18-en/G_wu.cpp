#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;
char s[maxn*2];
int sum[3][maxn*2];
int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	int A, B, C;
	A = B = C = 0;
	for(int i = n; i < 2*n; i++) {
		s[i] = s[i-n];
		if(s[i] == 'A') A++;
		if(s[i] == 'B') B++;
		if(s[i] == 'C') C++;
	}
	for(int i = 0; i < A; i++) if(s[i] != 'A') sum[0][0]++;
	for(int i = 0; i < B; i++) if(s[i] != 'B') sum[1][0]++;
	for(int i = 0; i < C; i++) if(s[i] != 'C') sum[2][0]++;

	for(int i = 1; i < 2*n; i++) {
		//A
		sum[0][i] = sum[0][i-1] - (s[i-1] == 'A' ? 0 : 1);
		if(i+A < 2*n) sum[0][i] += (s[i+A-1] == 'A' ? 0 : 1);
		//B
		sum[1][i] = sum[1][i-1] - (s[i-1] == 'B' ? 0 : 1);
		if(i+B < 2*n) sum[1][i] += (s[i+B-1] == 'B' ? 0 : 1);
		//C
		sum[2][i] = sum[2][i-1] - (s[i-1] == 'C' ? 0 : 1);
		if(i+C < 2*n) sum[2][i] += (s[i+C-1] == 'C' ? 0 : 1);
	}
	int ans = inf, at, bt;
	for(int i = 0; i < n; i++) {
		at = bt = 0;
		at = sum[0][i] + sum[1][i+A] + sum[2][i+A+B];
		bt = sum[0][i] + sum[2][i+A] + sum[1][i+A+C];
		ans = min(ans, min(at, bt)); 
	}
	printf("%d\n", ans);
	return 0;
}
