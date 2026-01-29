#include <cstdio>

using namespace std;

int t,n;
long long f[1002][6];
constexpr int mod = 1e9+7;

long long add(long long a,long long b) {
    return (a+b>=mod)?a-mod+b:a+b;
}

void dp(){
    f[1][0] = 1;
    for(int i=2;i<=1000;i++){
        f[i][0] = f[i-1][0];
        f[i][1] = (f[i-1][0] + 2*f[i-1][1])%mod;
        f[i][2] = add(f[i-1][0],f[i-1][2]);
        f[i][3] = (f[i-1][1] + 2*f[i-1][3])%mod;
        f[i][4] = (f[i-1][1]+f[i-1][2]+2*f[i-1][4])%mod;
        f[i][5] = (f[i-1][3]+f[i-1][4]+2*f[i-1][5])%mod;
    }
}

int main(){
    scanf("%d",&t);
    dp();
    while(t--){
        scanf("%d",&n);
        printf("%lld\n",f[n][5]);
    }
}