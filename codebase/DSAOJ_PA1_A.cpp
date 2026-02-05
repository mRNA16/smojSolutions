#include <cstdio>

using namespace std;

constexpr int N = 1e7+2;
int n,m,maxx;
int a[N],c[N];

int lowbit(int x){
    return x&-x;
}

void init(){
    c[0]=a[0];
    for(int i=1,j;i<=maxx;++i){
        c[i]+=a[i];
        j=i+lowbit(i);
        if(j<=maxx) c[j]+=c[i];
    }
}

int presum(int x){
    int ans=0;
    while(x>0){
        ans+=c[x];
        x=x-lowbit(x);
    }
    return ans;
}

int getsum(int l,int r){
    return presum(r)-presum(l-1);
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0,tmp;i<n;++i){
        scanf("%d",&tmp);
        maxx=(maxx>tmp)?maxx:tmp;
        a[tmp]=1;
    }
    init();
    for(int i=0,l,r;i<m;++i){
        scanf("%d %d",&l,&r);
        if(l>maxx) printf("0\n");
        else if(r>maxx) printf("%d\n",getsum(l,maxx));
        else printf("%d\n",getsum(l,r));
    }
}