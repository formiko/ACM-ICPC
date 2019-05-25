#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 5009;
bool a[maxn][maxn];
int du[maxn];
vector<int>e[maxn];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<n; ++i){
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		a[u][v]=true;
		du[u]++;
	}
	if(2==n){
		puts("0");
		return 0;
	}
	int ans=0, id1=0;
	for(int i=1; i<n; ++i){
		if(du[i]>ans){
			ans=du[i];
			id1=i;
		}	
	}
	int ans2=0, id2=0;
	for(int i=1; i<n; ++i){
		if(du[i]>ans2&&i!=id1&&a[id1][i]==0&&a[i][id1]==0){
			ans2=du[i];
			id2=i;
		}
	}
	int last_ans=ans+ans2;
	for(int i=1; i<=n; ++i){
		for(int j=0; j<e[i].size(); ++j){
			int ne=e[i][j];
			if(du[i]+du[ne]-1>last_ans){
				last_ans=du[i]+du[ne]-1;
			}
		}
	}
	printf("%d\n", last_ans);
	return 0;
}
