#include<cstdio>
using namespace std;
#define maxn 1000009
int n, m, row[maxn], column[maxn];
char value[maxn];
char s[maxn];
int swap(int &a, int &b){
    int p=a;
    a=b;
    b=p;
} 
void solve(){
    int tot=0;
    for(int i=1; i<=n; ++i){
        row[i]=i-1;
    }
    for(int i=1; i<=m; ++i){
        column[i]=i-1;
    }
    for(int i=0; i<n; ++i){
        scanf("%s", value+i*m); 
    }
    int Q;
    scanf("%d", &Q);
    int sel, x, y, p;
    while(Q--){
        scanf("%d%d%d", &sel, &x, &y);
        if(1==sel){
            p=row[x]*m+column[y];
            if('T'==value[p]){
                printf("Tree\n");
            }
            else if('i'==value[p]){
                printf("Phone\n");
            }
            else{
                printf("Empty\n"); 
            }
        }
        else if(2==sel){
            swap(row[x], row[y]);
        }
        else if(3==sel){
            swap(column[x], column[y]);
        }
    } 
}
int main(){
    int T=0;
    while(scanf("%d%d", &n, &m)!=EOF){
        printf("Case #%d:\n", ++T);
        solve();
    } 
    return 0;
} 
