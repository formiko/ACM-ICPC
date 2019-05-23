#include<cstdio>
using namespace std;
const int maxn = 1e5+9;
struct MC{
    int a, b;
    MC operator + (const MC & ot) const{
        return MC{a+ot.a, b+ot.b};
    }
    MC operator * (const MC & ot) const{
        return MC{a*ot.a-b*ot.b, b*ot.a+a*ot.b};
    }
    bool operator < (const MC & ot) const{
        return a<ot.a||(a==ot.a&&b<ot.b);
    }
    bool operator == (const MC & ot) const{
        return a==ot.a&&b==ot.b;
    }
    bool operator != (const MC & ot) const{
        return a!=ot.a||b!=ot.b;
    }
    void print(){
        printf("%d+%di", a, b);
    }
};
struct MA{
    MC a[2][2];
    MA operator + (const MA & ot) const{
        MA t;
        for(int i=0; i<2; ++i){
            for(int j=0; j<2; ++j){
                t.a[i][j]=a[i][j]+ot.a[i][j];
            }
        }
        return t;
    }
    MA operator * (const MA & ot) const{
        MA t;
        for(int i=0; i<2; ++i){
            for(int j=0; j<2; ++j){
                t.a[i][j]=MC{0, 0};
                for(int k=0; k<2; ++k){
                    t.a[i][j]=t.a[i][j]+(a[i][k]*ot.a[k][j]);
                }
            }
        }
        return t;
    }
    bool operator < (const MA & ot) const{
        for(int i=0; i<2; ++i){
            for(int j=0; j<2; ++j){
                if(a[i][j]<ot.a[i][j]){
                    return true;
                }
                else if(ot.a[i][j]<a[i][j]){
                    return false;
                }
            }
        }
        return false;
    }
    bool operator == (const MA & ot)const{
        for(int i=0; i<2; ++i){
            for(int j=0; j<2; ++j){
                if(a[i][j]!=ot.a[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    void print(){
        for(int i=0; i<2; ++i){
            for(int j=0; j<2; ++j){
                a[i][j].print();
                putchar('\t');
            }
            puts("");
        }
    }
};
struct node{
    int a[2];
};
MA ma[9];
int n, m, a[maxn];
void yes(){
    puts("YES");
}
bool dfs(MA state, int pos){
    if(pos>n){
        if(state==ma[m]){
            return true;
        }
        return false;
    }
    if(a[pos]){
        return dfs(state*ma[a[pos]], pos+1);
    }
    else{
        for(int i=1; i<=4; ++i){
               if(dfs(state*ma[i], pos+1)){
                return true;
               }
        }
        return false;
    }      
}
void solve(){
    scanf("%d", &n);
    int cnt0=0;
    for(int i=1; i<=n; ++i){
        scanf("%d", &a[i]);
        if(0==a[i]){
            ++cnt0;
        }
    }
    scanf("%d", &m);
    if(cnt0>=2){
        yes();
        return ;
    }
    MA start=ma[1];
    if(dfs(start, 1)){
        yes();
    }
    else{
        puts("NO");
    }  
         
}
int main(){
    int tmp[][2][2][2]={
        {   {{0, 0}, {0, 0}},
            {{0, 0}, {0, 0}}
        },
        {
            {{1, 0}, {0, 0}},
            {{0, 0}, {1, 0}}
        },
        {
            {{0, 0}, {1, 0}},
            {{-1, 0}, {0, 0}}
        },
        {
            {{0, 0}, {0, 1}},
            {{0, 1}, {0, 0}}
        },
        {
            {{0, 1}, {0, 0}},
            {{0, 0}, {0, -1}}
        },
        {
            {{-1, 0}, {0, 0}},
            {{0, 0}, {-1, 0}}
        },
        {
            {{0, 0}, {0, -1}},
            {{0, -1}, {0, 0}}
        },
        {
            {{0, 0}, {-1, 0}},
            {{1, 0}, {0, 0}}
        },
        {
            {{0, -1}, {0, 0}},
            {{0, 0}, {0, 1}}
        }
 
    }; 
     
 
    for(int i=0; i<=8; ++i){
        for(int j=0; j<2; ++j){
            for(int k=0; k<2; ++k){
                ma[i].a[j][k]=MC{tmp[i][j][k][0], tmp[i][j][k][1]};
            }
        }
    }
    int T;
    scanf("%d", &T);
    while(T--){
        solve();
    }
     
    return 0;
}