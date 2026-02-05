#include <iostream>
#include <cstdlib>
using namespace std;

int n;
long long ans;
constexpr int N=4*1e6+2;
struct tower{
    int x,y;
    tower(){}
    tower(int a,int b):x(a),y(b){}
}t[N],ct[N];

int cmp(const void* a, const void* b) {
    tower* t1 = (tower*)a;
    tower* t2 = (tower*)b;
    return t1->x - t2->x;
}

void MergeSort(tower* t,int l,int r){
    if(l==r) return;
    int mid = l+(r-l)/2;
    MergeSort(t,l,mid);
    MergeSort(t,mid+1,r);
    for(int i=l;i<=r;++i){
        ct[i]=t[i];
    }
    int p=l;
    int q=mid+1;
    int k=0;
    while(p<=mid&&q<=r){
        if(ct[p].y<ct[q].y){
            t[l+k++]=ct[p++];
            ans+=r-q+1;
        } else{
            t[l+k++]=ct[q++];
        }
    }
    if(p<=mid){
        while(p<=mid) t[l+k++]=ct[p++];
    } else{
        while(q<=r) t[l+k++]=ct[q++];
    }

    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i=0,a,b;i<n;++i){
        cin>>a>>b;
        t[i]={a,b};
    }

    qsort(t,n,sizeof(tower),cmp);
    MergeSort(t,0,n-1);
    cout<<ans;
}