#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int m,n;
int main(){
    cin>>m>>n;
    getchar();

    vector<string> tmpl(m);
    for(int i=0;i<m;i++){
        getline(cin,tmpl[i]);
    }

    unordered_map<string,string> vars;
    for(int i=0;i<n;i++){
        string l;
        getline(cin,l);
        size_t space = l.find(' ');
        string name = l.substr(0,space);
        size_t fquote = l.find('"');
        size_t lquote = l.find_last_of('"');
        string val = l.substr(fquote+1,lquote-fquote-1);
        vars[name] = val;
    }

    for(const string& line:tmpl){
        string res;
        res.reserve(line.size());
        size_t sp=0,cur=0;
        while((sp=line.find("{{ ",cur))!=string::npos){
            res.append(line.substr(cur,sp-cur));

            size_t ep = line.find(" }}",sp+3);
            string name = line.substr(sp+3,ep-sp-3);
            if(vars.count(name)){
                res.append(vars[name]);
            }
            cur = ep+3;
        }
        res.append(line,cur,string::npos);
        cout << res << endl;
    }
}