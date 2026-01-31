#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>
using namespace std;

int n;

/* struct rectangle{
    int lx,ly;
    int rx,ry;
    int xlen,ylen;
    int area;
    rectangle(){}
    rectangle(int a,int b,int c,int d):lx(a),ly(b),rx(c),ry(d){
        xlen = rx - lx;
        ylen = ry - ly;
        area = xlen*ylen;
    }
};

int both(const rectangle& a,const rectangle& b){
    int x=0,y=0;
    const rectangle& lf = (a.lx<=b.lx)?a:b;
    const rectangle& ri = (a.lx<=b.lx)?b:a;
    if(lf.rx>ri.lx) x=min(lf.rx-ri.lx,ri.xlen);

    const rectangle& low = (a.ly<=b.ly)?a:b;
    const rectangle& high = (a.ly<=b.ly)?b:a;
    if(low.ry>high.ly) y=min(low.ry-high.ly,high.ylen);
    return x*y;
}*/

/* 
数据规模小，暴力遍历
数据规模大需要用扫描线，后续学习后提交扫描线版本
*/
int main(){
    cin>>n;
    int a,b,c,d;
    unordered_set<long long> vis;
    long long key;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c>>d;
        // 用左下角点坐标代替正方形
        // 更简单的做法开二维数组，这里是GPT给的bitmap的替代方法，用了用学习一下
        for(int j=a;j<c;j++){
            for(int k=b;k<d;k++){
                key = ((long long)j << 32) | k;
                vis.insert(key);
            }
        }
    }

    cout<<vis.size()<<endl;
}