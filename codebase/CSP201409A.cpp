#include <iostream>
#include <climits>

using namespace std;

int n,ans;
int a[10005];

int main(){
    cin >> n;
    int t;
    int maxx = -INT_MAX;
    int minn = INT_MAX;
    for(int i=0;i<n;i++){
        cin>>t;
        if(t>maxx) maxx = t;
        if(t<minn) minn = t;
        a[t]++;
    }

    for(int i=minn;i<maxx;i++){
        if(a[i]!=0&&a[i+1]!=0){
            ans+=a[i]*a[i+1];
        }
    }
    cout<<ans<<"\n";
    return 0;
}