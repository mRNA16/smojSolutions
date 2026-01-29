#include <cstdio>
#include <cstdlib>
#include <cstring>
#define maxn 10001
#define mod 1000000007
using namespace std;
int t;
int h,k;
int *s,*spre,*spre2;

void pre_alloc(){
    s = (int*)(malloc(sizeof(int) * maxn));
    spre = (int*)(malloc(sizeof(int) * maxn));
    spre2 = (int*)(malloc(sizeof(int) * maxn));
}

void init(){
    spre2[0] = 0;
    spre[0] = 1;
    spre[1] = 0;
    s[0] = 1;
}

void roll(){
    int* tmp = spre2;
    spre2 = spre;
    spre = s;
    s = tmp;
}

int main(){
    pre_alloc();
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&h,&k);
        init();
        for(int i=1;i<=h;i++){
            s[0] = 1;
            for(int j=1;j<=i;j++){
                s[j] = (spre[j-1] + spre2[j-1])%mod;
            }
            s[i] = 1; 
            if(i<h) roll();
        }
        printf("%d\n",s[k]);
    }
}