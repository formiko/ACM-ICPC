//没有考虑到对换位置的情况的错误代码
#include<bits/stdc++.h>
using namespace std;
const int bitmap_size = 1<<24;
const int maxn = 16;
const int maxk = 3;
int n, m, k;
bool g[maxn][maxn];
bool vis[bitmap_size];
struct Point{
	int x, y;
};
struct node{
	Point p[3];
	int step;
};
queue<node>q;
node start, my_end;
bool is_in(Point a){
	return 0<=a.x&&a.x<n&&0<=a.y&&a.y<m;
}
int my_hash(node a){
	int re=0;
	for(int i=0; i<k; ++i){
		re+=(a.p[i].x<<(8*i));
		re+=(a.p[i].y<<(8*i+4));
	}	
	return re;
}
int dx[]={0, 0, 0, -1, 1};
int dy[]={0, -1, 1, 0, 0};
bool same_Point(Point a, Point b){
	return a.x==b.x&&a.y==b.y;
}
bool location_equal(node a, node b){
	for(int i=0; i<k; ++i){
		if(!same_Point(a.p[i], b.p[i])){
			return false;
		}
	}
	return true;
}
void print(node a){
	printf("** step is %d %d\n", a.step, my_hash(a));
	for(int i=0; i<k; ++i){
		printf("%d %d\n", a.p[i].x, a.p[i].y);
	}
}
int walk(node cur, int ik){
	if(ik==k){
		for(int i=0; i<k; ++i){
			for(int j=i+1; j<k; ++j){
				if(same_Point(cur.p[i], cur.p[j])){
					return 0;
				}
			}
		}
		int h=my_hash(cur);
		++cur.step;
		if(vis[h]){
			return 0;
		}
		if(location_equal(cur, my_end)){
			return cur.step;
		}
		vis[h]=true;
		q.push(cur);
	}
	for(int i=0; i<5; ++i){
		cur.p[ik].x+=dx[i];
		cur.p[ik].y+=dy[i];
		if(is_in(cur.p[ik])&&!g[cur.p[ik].x][cur.p[ik].y]){
			int t=walk(cur, ik+1);
			if(t){
				return cur.step;
			}
		}
		cur.p[ik].x-=dx[i];
		cur.p[ik].y-=dy[i];	
	}
	return 0;
}
int main(){
	freopen("data.in", "r", stdin);
	scanf("%d%d%d", &n, &m, &k);
	for(int i=0; i<k; ++i){
		scanf("%d%d", &start.p[i].x, &start.p[i].y);
	}
	for(int i=0; i<k; ++i){
		scanf("%d%d", &my_end.p[i].x, &my_end.p[i].y);
	}
	int v;
	scanf("%d", &v);
	for(int i=1; i<=v; ++i){
		int x, y;
		scanf("%d%d", &x, &y);
	   	g[x][y]=1;	
	}	
	vis[my_hash(start)]=true;	
	start.step=0;
	q.push(start);
	while(!q.empty()){
		node cur=q.front();
		q.pop();
		int ans=walk(cur, 0);	
		print(cur);
		if(ans){
			printf("%d\n", ans);
			return 0;
		}
	}	
	puts("end");
	return 0;
}
