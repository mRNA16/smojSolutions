#include <cstdio>
#include <climits>
#include <cmath>
#define N 1000005
using namespace std;
int n;
long long maxx = -LONG_LONG_MAX;
int a[N];
long long dp[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        // 可以滚动优化
        dp[i] = max(dp[i-1]+a[i],(long long)a[i]);
        maxx = max(dp[i],maxx);
    }
    printf("%lld",maxx);
}
