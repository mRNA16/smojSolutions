#include <cstdio>

using namespace std;
constexpr int mod = 1e9+7;
inline int add(int a,int b) {return (a+b>=mod)?a-mod+b:a+b;}
inline int mul(int a,int b) {return 1ll * a * b % mod;}

struct Matrix
{
    int mat[2][2];
    Matrix(bool o=0) {
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                mat[i][j] = o;
            }
        }
    }

    Matrix operator*(const Matrix& other) const{
        Matrix res;
        for(int i=0;i<2;i++){
            for(int k=0;k<2;k++){
                for(int j=0;j<2;j++){
                    res.mat[i][j] = add(res.mat[i][j],mul(mat[i][k],other.mat[k][j]));
                }
            }
        }
        return res;
    }
};

int solve(long long n){
    Matrix p(1),res;
    res.mat[0][0] = res.mat[1][1] = 1;
    p.mat[0][0] = 0;
    while(n>0){
        if(n&1) res = res*p;
        p = p*p;
        n>>=1; 
    }
    return res.mat[0][1];
}

int t;
long long n;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        printf("%d\n",solve(n));  
    }
}
