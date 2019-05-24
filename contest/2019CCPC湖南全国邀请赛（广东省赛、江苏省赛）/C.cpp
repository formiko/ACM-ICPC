#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
const int MAXN=4*27100;
int a[MAXN];
int b[MAXN];
int upa[MAXN];
int dwa[MAXN];
int pos[MAXN];
int sum[MAXN];
int ans[MAXN];
int n,m,k;
void add(int p, int x){ //¸øÎ»ÖÃpÔö¼Óx
    while(p < MAXN) sum[p] += x, p += p & -p;
}
int ask(int p){ //ÇóÎ»ÖÃpµÄÇ°×ººÍ
    int res = 0;
    while(p) res += sum[p], p -= p & -p;
    return res;
}
struct node
{
    int l,r,id;
} q[MAXN];
bool cmp(node x,node y)
{
    return pos[x.l]<pos[y.l]||(pos[x.l]==pos[y.l]&&x.r<y.r);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[++tot]=a[i],b[++tot]=a[i]-k-1,b[++tot]=a[i]+k;
	}
	sort(b+1,b+1+tot);
	tot=unique(b+1,b+1+tot)-b-1;
	for(int i=1;i<=n;i++)
    upa[i]=lower_bound(b+1,b+1+tot,a[i]+k)-b,dwa[i]=lower_bound(b+1,b+1+tot,a[i]-k-1)-b,a[i]=lower_bound(b+1,b+1+tot,a[i])-b;
    int blog=sqrt(n);
    for(int i=1;i<=n;i++)
    pos[i]=i/blog+1;
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d",&q[i].l,&q[i].r);
    	q[i].id=i; 
	}
	sort(q+1,q+1+m,cmp);
	int l=q[1].l,r=q[1].l-1,res=0;
    for(int i=1;i<=m;i++)
    {
        while(r<q[i].r)
        {
            r++;
            res+=ask(upa[r])-ask(dwa[r]);
            add(a[r],1);
        }
        while(r>q[i].r)
        {
            add(a[r],-1);
            res-=ask(upa[r])-ask(dwa[r]);
            r--;
        }
        while(l<q[i].l)
        {
            add(a[l],-1);
            res-=ask(upa[l])-ask(dwa[l]);
            l++;
        }
        while(l>q[i].l)
        {
            l--;
            res+=ask(upa[l])-ask(dwa[l]);
            add(a[l],1);
        }
        ans[q[i].id]=res;
    }
    for(int i=1;i<=m;i++)
    printf("%d\n",ans[i]);
	return 0;
}
