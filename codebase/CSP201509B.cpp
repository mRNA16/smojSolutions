#include <iostream>
#include <numeric>

using namespace std;

int y,d;
int m,lf;
int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int pref[13];

inline bool sp(int y){
    return (y%400)==0||(y%4==0&&y%100!=0);
}

int main(){
    cin>>y>>d;
    if(sp(y)) days[1]=29;
    partial_sum(days,days+12,pref+1);
    for(int i=12;i>=0;i--){
        if(d>pref[i]){
            lf = d-pref[i]; 
            m = i+1;
            break;
        } else if(d==pref[i]){
            lf = days[i-1];
            m = i;
            break;
        }
    }
    cout<<m<<"\n"<<lf<<"\n";
}