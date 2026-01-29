#include <cstdio>
#define mod 11
using namespace std;

int a[10];
int ans;
char c;

int main(){
    scanf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&c);
    for(int i=0;i<9;i++){
        ans = (ans + a[i]*(i+1))%mod;
    }
    if(ans==((c=='X')?10:c-'0')) printf("Right");
    else printf("%1d-%1d%1d%1d-%1d%1d%1d%1d%1d-%c",a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],(ans==10)?'X':'0'+ans);
}