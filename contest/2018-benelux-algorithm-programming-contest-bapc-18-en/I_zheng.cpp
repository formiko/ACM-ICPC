#include<bits/stdc++.h>
using namespace std;
/*
 *  Dinic ¡Á?¡ä¨®¨¢¡Â O(V^2 * E)
 *  INIT: ne=2; head[]???a0; addedge()?¨®¨¨??¨´¨®D??; 
 *  CALL: flow(n, s, t);
 */
typedef long long ll;
const ll inf = 1e17;   // max of cost
const int E = 5000020;
const int N = 100020;
ll p[N];
int si[N];
ll ci[N]; 
ll cango[N];
struct edge
{
    int x, y, nxt;
    ll c;
} bf[E];
int ne, head[N], cur[N], ps[N], dep[N];
void init()
{
    ne=2;
    memset(head,-1,sizeof(head));
    memset(bf,0,sizeof(bf));
}
void addedge(int x, int y, ll c)
{   //  add an arc(x->y, c);    vertex:0~n-1;
    bf[ne].x = x;
    bf[ne].y = y;
    bf[ne].c = c;
    bf[ne].nxt = head[x];
    head[x] = ne++;
    bf[ne].x = y;
    bf[ne].y = x;
    bf[ne].c = 0;
    bf[ne].nxt = head[y];
    head[y] = ne++;
    return ;
}

ll flow(int n, int s, int t)
{
    ll tr, res = 0;
    int i, j, k, f, r, top;
    while (1)
    {
        memset(dep, -1, n * sizeof(int));
        for (f = dep[ps[0] = s] = 0, r = 1; f != r;)
        {
            for (i = ps[f++], j = head[i]; j; j = bf[j].nxt)
            {
                if (bf[j].c && -1 == dep[k = bf[j].y])
                {
                    dep[k] = dep[i] + 1;
                    ps[r++] = k;
                    if (k == t)
                    {
                        f = r;
                        break;
                    }
                }
            }
        }
        if (-1 == dep[t])
        {
            break;
        }
        memcpy(cur, head, n * sizeof(int));
        for (i = s, top = 0; ;)
        {
            if (i == t)
            {
                for (k = 0, tr = inf; k < top; ++k)
                {
                    if (bf[ps[k]].c < tr)
                    {
                        tr = bf[ps[f = k]].c;
                    }
                }
                for (k = 0; k < top; ++k)
                {
                    bf[ps[k]].c -= tr, bf[ps[k]^1].c += tr;
                }
                res += tr;
                i = bf[ps[top = f]].x;
            }
            for (j = cur[i]; cur[i]; j = cur[i] = bf[cur[i]].nxt)
            {
                if (bf[j].c && dep[i] + 1 == dep[bf[j].y])
                {
                    break;
                }
            }
            if (cur[i])
            {
                ps[top++] = cur[i];
                i = bf[cur[i]].y;
            }
            else
            {
                if (0 == top)
                {
                    break;
                }
                dep[i] = -1;
                i = bf[ps[--top]].x;
            }
        }
    }
    return res;
}

const int MAXN = 100020;
ll B[1100000];
struct qNode
{
    int v;
    ll c;
    qNode(int _v = 0, ll _c = 0) : v(_v), c(_c) {}
    bool operator < (const qNode &r) const
    {
        return c > r.c;
    }
};

struct Edge
{
    int v;
    ll cost;
    Edge(int _v = 0, ll _cost = 0) : v(_v), cost(_cost) {}
};

vector<Edge> E2[MAXN];
bool vis[MAXN];
ll dist[20][MAXN];     //  ¡Á??¨¬?¡¤?¨¤¨¤?

void Dijkstra(int cur,int n, int start)     //  ¦Ì?¦Ì?¡À¨¤o?¡ä¨®1?a¨º?
{
    memset(vis, false, sizeof(vis));
    fill(dist[cur],dist[cur]+MAXN,inf);
    priority_queue<qNode> que;

    while (!que.empty())
    {
        que.pop();
    }
    dist[cur][start] = 0;
    que.push(qNode(start, 0));
    qNode tmp;

    while (!que.empty())
    {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (int i = 0; i < E2[u].size(); i++)
        {
            int v = E2[u][i].v;
            ll cost = E2[u][i].cost;
            if (!vis[v] && dist[cur][v] > dist[cur][u] + cost)
            {
                dist[cur][v] = dist[cur][u] + cost;
                que.push(qNode(v, dist[cur][v]));
            }
        }
    }
}

void addEdge2(int u, int v, ll w)
{
    E2[u].push_back(Edge(v, w));
    E2[v].push_back(Edge(u, w));
}

int main()
{
	int n,m,s,u,v;
	ll sum=0;
	ll w;
	init();
	scanf("%d%d%d",&n,&m,&s);
	int S=0;
	int T=n+s+1;
	for(int i=1;i<=n;i++)
	{
	    scanf("%lld",&p[i]);
		sum+=p[i];	
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&u,&v,&w);
		addedge(u,v,w);
		addEdge2(u,v,w);
	}
	for(int i=1;i<=s;i++)
	{
		scanf("%d%lld",&si[i],&ci[i]);
	}
	for(int i=1;i<=s;i++)
	Dijkstra(i,n,si[i]);  
	int tot=0;
	for(int i=1;i<=s;i++)
	{
		for(int j=1;j<=n;j++)
		{
			B[++tot]=dist[i][j];
		}
	 } 
	 sort(B+1,B+tot+1);
	 tot=unique(B+1,B+tot+1)-(B+1);
     ll l=1;
	 ll r=tot;
	 ll mid,ans;
	 ans=0;
     while(l<=r)
    {
        init();
        memset(cango,0,sizeof(cango));
		mid=(l+r)/2;
        for(int i=1;i<=n;i++)
        {
        	for(int j=1;j<=s;j++)
        	{
        		if(dist[j][i]<=B[mid])
                {
                     addedge(i,n+j,inf);
					 cango[i]+=ci[j];	
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(cango[i]<p[i])
			{
				l=mid+1;
				continue;
			}
		}
        for(int i=1;i<=n;i++)
        addedge(S,i,p[i]);
        for(int i=1;i<=s;i++)
        addedge(n+i,T,ci[i]);
        ll res=flow(n+s+2,S,T);
        if(res==sum) r=mid-1,ans=B[mid];
        else l=mid+1;
    }
    printf("%lld\n",ans);
}
