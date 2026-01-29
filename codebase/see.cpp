#include <iostream>
#include <vector>
using namespace std;
int see(vector<int> arr){
    int ans = 0;
    int max = -1;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>max) {
            ans +=1;
            max = arr[i]; 
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector< vector<int> > h(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> h[i][j];
        }
    }

    vector< vector<int> > ans(n,vector<int>(4));
    for(int i=0;i<n;i++){
        int l,r,u,d;

        l = see(h[i]);

        vector<int> tmp_r;
        for(int j=n-1;j>=0;j--){
            tmp_r.push_back(h[i][j]);
        }
        r = see(tmp_r);

        vector<int> tmp_u;
        for(int j=0;j<n;j++){
            tmp_u.push_back(h[j][i]);
        }
        u = see(tmp_u);

        vector<int> tmp_d;
        for(int j=n-1;j>=0;j--){
            tmp_d.push_back(h[j][i]);
        }
        d = see(tmp_d);

        ans[i][0] = l;
        ans[i][1] = r;
        ans[i][2] = u;
        ans[i][3] = d;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++) {
            cout << ans[i][j] << " ";
        }
        cout << ans[i][3] << "\n";
    }
}