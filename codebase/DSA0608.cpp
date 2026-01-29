#include <iostream>
#define N 1000000007
using namespace std;

int h;
unsigned long long dp[100005];
int main(){
    cin >> h;
    dp[1] = 2;
    dp[2] = 4;
    for(int i=3;i<=h;i++){
        dp[i] = (dp[i-1] + dp[i-2] + 1)%N;
    }

    cout << dp[h];
}