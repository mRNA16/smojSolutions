#include <cstdio>
#define ll long long
using namespace std;


ll n;
int m;
constexpr int MAX_NODES = 130;
constexpr int mod = 1e9+7;

// 最初的提交这个地方写成a-mod+b>=mod了，没发现还以为是其他地方的问题，40pts的提交都是源自这里
// 一定要仔细！！！
ll add(ll a,ll b){
    return (a-mod+b>=0)?a-mod+b:a+b;
}

struct Matrix {
    long long mat[MAX_NODES][MAX_NODES];
    int size;

    Matrix(int s) : size(s) {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                mat[i][j] = 0;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res(size);
        for (int k = 0; k < size; k++) {
            for (int i = 0; i < size; i++) {
                if (mat[i][k] == 0) continue;
                for (int j = 0; j < size; j++) {
                    res.mat[i][j] = add(res.mat[i][j],(mat[i][k] * other.mat[k][j])%mod);
                }
            }
        }
        return res;
    }
};

Matrix power(Matrix a, long long b) {
    Matrix res(a.size);
    for (int i = 0; i < a.size; i++) res.mat[i][i] = 1;
    while (b > 0) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

inline int gesp(int bin,int idx){
    if(idx>=m||idx<0) return -1;
    return (bin>>idx)&1;
}

// DFS这样不改变cur_s一点问题也没有，LLM一直说这里有问题，第一次做状压DP不够自信，被骗了一下午
void dfs(int cur,int cur_s,int nxt_s,Matrix& T){
    if(cur==m) {
        if(++T.mat[cur_s][nxt_s]==mod) T.mat[cur_s][nxt_s]=0;
        return;
    }
    if(gesp(cur_s,cur)==0){
        if(gesp(cur_s,cur+1)==0&&gesp(nxt_s,cur)==0) dfs(cur+2,cur_s,nxt_s|(1<<cur),T);
        if(gesp(cur_s,cur+1)==0&&gesp(nxt_s,cur+1)==0) dfs(cur+2,cur_s,nxt_s|(1<<(cur+1)),T);
        if(gesp(nxt_s,cur+1)==0&&gesp(nxt_s,cur)==0) dfs(cur+1,cur_s,nxt_s|(1<<cur)|(1<<(cur+1)),T);
        if(gesp(nxt_s,cur-1)==0&&gesp(nxt_s,cur)==0) dfs(cur+1,cur_s,nxt_s|(1<<cur)|(1<<(cur-1)),T);
    } else {
        dfs(cur+1,cur_s,nxt_s,T);
    }
}

int main(){
    scanf("%lld %d",&n,&m);
    // 这里是个大问题，我错误的剪枝为%6!=0，80pts的提交就是这里
    if((n*m)%3!=0){
        printf("0\n");
        return 0;
    }
    int cnt = 1<<m;
    Matrix T(cnt);
    for(int i=0;i<cnt;i++){
        dfs(0,i,0,T);
    }
    Matrix res = power(T,n-1);
    printf("%lld\n",res.mat[0][cnt-1]);
    return 0;
}