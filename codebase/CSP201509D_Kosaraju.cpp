/*Kosaraju*/
#include <cstdio>
#include <vector>
#define N 10005
#define M 100005
using namespace std;

int n,m;
int head[N],ver[M],nxt[M];
int head_rev[N],ver_rev[M],nxt_rev[M];
int cnt=1,cnt_rev=1;
int scnt,scc[N];

bool vis[N];
bool vis_rev[N];
vector<int> s;
void add(int a,int b){
    ver[++cnt] = b;
    nxt[cnt] = head[a];
    head[a] = cnt;
}

void add_rev(int a,int b){
    ver_rev[++cnt_rev] = a;
    nxt_rev[cnt_rev] = head_rev[b];
    head_rev[b] = cnt_rev;
}

void dfs(int u){
    vis[u] = true;
    for(int i=head[u];i!=0;i=nxt[i]){
        int v = ver[i];
        if(!vis[v]) dfs(v);
    }
    s.push_back(u);
}

void dfs_rev(int u){
    vis_rev[u] = true;
    scc[scnt]++;
    for(int i=head_rev[u];i!=0;i=nxt_rev[i]){
        int v = ver_rev[i];
        if(!vis_rev[v]) dfs_rev(v);
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0,a,b;i<m;i++){
        scanf("%d %d",&a,&b);
        add(a,b);
        add_rev(a,b);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    
    for(int i=(int)s.size()-1;i>=0;i--){
        if(!vis_rev[s[i]]) {
            dfs_rev(s[i]);
            scnt++;
        }
    }

    long long ans=0;
    for(int i=0;i<scnt;i++){
        ans+=scc[i]*(scc[i]-1)/2;
    }
    printf("%lld",ans);
}