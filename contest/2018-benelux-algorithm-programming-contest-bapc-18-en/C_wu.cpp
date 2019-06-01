#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main() {
	int V;
	int ans = inf;
	scanf("%d", &V);
	int m = floor(sqrt((double)V+0.5));
	for(int a = 1; a <= m; a++) 
		for(int b = 1; b <= m; b++) {
			int c = V / (a*b);
			if(a*b*c != V) continue;
			ans = min(ans, 2*(a*b+a*c+b*c));
		}
	printf("%d\n", ans);
	return 0;
}
