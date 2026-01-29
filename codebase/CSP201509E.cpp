#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
typedef long long ll;
using namespace std;

constexpr int N = 2e5+6; 
constexpr int LEN = 2e5+6;
constexpr int SIZE = 2e5+6;
constexpr ll INF = 1e16;

struct Matrix {
    int size;
    vector<vector<ll>> mat;
    Matrix(int s):size(s) {
        mat.assign(size,vector<ll>(size,-INF));
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res(size);
        for(int i=0;i<size;i++){
            for(int k=0;k<size;k++){
                if(mat[i][k]<=-INF) continue;
                for(int j=0;j<size;j++){
                    if(other.mat[k][j] <=-INF) continue;
                    res.mat[i][j] = max(res.mat[i][j],mat[i][k] + other.mat[k][j]);
                }
            }
        }
        return res;
    }
};

namespace AC{
    struct Node {
        int son[26];
        ll ans;
        int fail;
        int idx;
        int du;

        void init(){
            memset(son,0,sizeof(son));
            ans = fail = idx = du = 0;
        }
    } tr[SIZE];

    int tot;
    int ans[N],pidx;

    void init(){
        tot = pidx = 0;
        tr[0].init();
    }

    void insert(char s[],int &idx){
        int u = 0;
        for(int i=1;s[i];i++){
            int &son = tr[u].son[s[i]-'a'];
            if(!son) son = ++tot,tr[son].init();
            u = son; 
        }
        if(!tr[u].idx) tr[u].idx = ++pidx;
        tr[u].ans++;
        idx = tr[u].idx; 
    }

    void build(){
        queue<int> q;
        for(int i=0;i<26;i++)
            if(tr[0].son[i]) q.push(tr[0].son[i]);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i=0;i<26;i++){
                if(tr[u].son[i]) {
                    tr[tr[u].son[i]].fail = tr[tr[u].fail].son[i];
                    tr[tr[tr[u].fail].son[i]].du++;
                    tr[tr[u].son[i]].ans += tr[tr[tr[u].son[i]].fail].ans;
                    q.push(tr[u].son[i]);
                }
                else
                    tr[u].son[i] = tr[tr[u].fail].son[i]; 
            }
        }
    }

    ll solve(ll m){
        int size = tot + 1;
        Matrix G(size);

        for(int i=0;i<size;i++){
            for(int j=0;j<26;j++){
                int v = tr[i].son[j];
                G.mat[i][v] = max(G.mat[i][v],tr[v].ans);
            }
        }

        Matrix res(size);
        for(int i=0;i<size;i++) res.mat[i][i] = 0;

        ll tmp = m;
        while(tmp>0){
            if(tmp&1) res=res*G;
            G=G*G;
            tmp >>= 1;
        }

        ll ans=0;
        for(int i=0;i<size;i++){
            ans = max(ans,res.mat[0][i]);
        }

        return ans;
    }
}

int n;
ll m;


char s[LEN];
int idx[N];

int main(){
    AC::init();
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        AC::insert(s,idx[i]);
        AC::ans[i] = 0; 
    }
    AC::build();
    printf("%lld\n",AC::solve(m));
}