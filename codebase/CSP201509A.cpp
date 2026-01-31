#include <iostream>

using namespace std;

int n;
int a[1005];
int ans;

int main(){
    cin>>n>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i] - a[i-1]!=0) ans++;
    }
    cout<<(ans+1);
    return 0;
}