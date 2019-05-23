#include<cstdio>
using namespace std;
#define ll long long
int a[69];
ll dp[69][2][2];
ll dfs(int pos, int pre2, int pre1, bool limit){
	if(-1==pos)	return 1;
	if(!limit&&dp[pos][pre2][pre1])	return dp[pos][pre2][pre1];
	int up=limit?a[pos]:1;
	ll re=0;
	for(int i=0; i<=up; ++i){
		if(1==pre2&&1==i)	continue;
		re+=dfs(pos-1, pre1, i, limit&&i==a[pos]);
	}
	if(!limit)	dp[pos][pre2][pre1]=re;
	return re;
}
ll solve(ll x){
	int pos=0;
	while(x){
		a[pos++]=x%2;
		x/=2;
	}
	return dfs(pos-1, 0, 0, true);
}
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		ll l, r;
		scanf("%lld%lld", &l, &r);
		printf("%lld\n", solve(r)-solve(l-1));
	}
	return 0;
}