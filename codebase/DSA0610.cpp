#include "fibavl.h"
#include <cstdlib>
#define maxn 42
#define mod 1000000007

using namespace std;

int *s,*spre,*spre2;
int first[maxn],offset[maxn];
void pre_alloc(){
    s = (int*)(malloc(sizeof(int) * maxn));
    spre = (int*)(malloc(sizeof(int) * maxn));
    spre2 = (int*)(malloc(sizeof(int) * maxn));
}

void init(){
    spre2[0] = 0;
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

void dprint(int k,int h,int limit){
    print(first[k] + offset[k]++);
    if(k+1<=limit){
        if(h-2>=0) dprint(k+1,h-2,limit);
        if(h-1>=0) dprint(k+1,h-1,limit);
    }
    
}

void preorder(int h)
{   pre_alloc();
    // 首先构建s(k,h)数组，s[k]为深度为k层的节点个数
    init();
    for(int i=1;i<=h;i++){
        s[0] = 1;
        for(int j=1;j<=i;j++){
            s[j] = (spre[j-1] + spre2[j-1])%mod;
        }
        s[i] = 1; 
        if(i<h) roll();
    }
    for(int i=1;i<=h;i++){
        first[i] = first[i-1] + s[i-1];
    }


    dprint(0,h,h);    
}