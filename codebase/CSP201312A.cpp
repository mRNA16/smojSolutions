#include <cstdio>

using namespace std;

int n;
int maxVal = -1,maxCount;
int a[10002];
int main(){
    scanf("%d",&n);
    int t;
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(++a[t]>maxCount||(a[t]==maxCount&&t<maxVal)) {
            maxCount = a[t];
            maxVal = t;
        }
    }
    printf("%d",maxVal);
}