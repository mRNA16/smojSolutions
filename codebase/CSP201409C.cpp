#include <iostream>

using namespace std;

string target,txt;
int cap;
int n;

void lower(string& s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='Z') s[i]-='A'-'a';
    }
}

string copylower(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]>='A'&&s[i]<='Z') s[i]-='A'-'a';
    }
    return s;
}

int main(){
    cin >> target >> cap >>n;
    if(cap==1){
        for(int i=0;i<n;i++){
            cin >> txt;
            if(txt.find(target)!=string::npos) cout<<txt<<endl;
        }
    } else {
        lower(target);
        for(int i=0;i<n;i++){
            cin >> txt;
            if(copylower(txt).find(target)!=string::npos) cout<<txt<<endl;
        }
    }
}