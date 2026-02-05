#include <iostream>

using namespace std;

int n;
string s;

void process(string& s,int idx,char c){
    s.insert(idx,1,c);
    int cur=idx;
    while(cur>=0&&cur<s.length()){
        int l=cur;
        int r=cur;
        while(l>0&&s[l-1]==c) l--;
        while(r<s.length()-1&&s[r+1]==c) r++;
        if(r-l>=2){
            s.erase(l,r-l+1);
            if(l>=s.length()){
                if(s.empty()) break;
                cur=s.length()-1;
            } else{
                cur=l;
            }
            c=s[cur];
        } else{
            break;
        }
    }
    if(!s.empty()) cout<<s<<"\n";
    else cout<<'-'<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    getline(cin, s);
    cin>>n;
    char c;
    for(int i=0,idx;i<n;++i){
        cin>>idx>>c;
        process(s,idx,c);
    }
}