#include <cstdio>
#include <cmath>
#include <limits.h>
#include <stack>

using namespace std;

int n;
int h[100005];
int l[100005],r[100005];
long long ans = -LONG_LONG_MAX;
int main(){
    scanf("%d",&n);
    h[0] = -INT_MAX;
    stack<int> sta;
    sta.push(0);
    for(int i=1;i<=n+1;i++){
        if(i<n+1) scanf("%d",&h[i]); else h[i] = -INT_MAX;
        while(1){
            if(h[i]>=h[sta.top()]){
                l[i] = sta.top();
                sta.push(i);
                break;
            }
            if(h[i]<h[sta.top()]){
                int idx = sta.top();
                sta.pop();
                r[idx] = i;
            }
        }
    }
    for(int i=1;i<=n;i++){
        long long len = r[i]-l[i]-1;
        ans = max(ans,len*h[i]);
    }
    printf("%lld",ans);
}