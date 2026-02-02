#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

struct point{
    int x,y;
};

struct cus{
    int x,y,count;
};

struct ty{
    int type,dis;
    ty():type(0),dis(-1){}
};

int n,m,k,d;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
long long ans;
ty dis[1005][1005];
cus ord[1000005];
queue<point> q;

void bfs(){
    point cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        for(int i=0,x,y;i<4;i++){
            x = cur.x + dx[i];
            y = cur.y + dy[i];

            if(x<1||x>n||y<1||y>n) continue;

            if(dis[x][y].type!=-1&&dis[x][y].dis==-1){
                dis[x][y].dis = dis[cur.x][cur.y].dis + 1;
                q.push({x,y});
            }
        }
    }
}

int main(){
    cin >> n >> m >> k >> d;
    for(int i=0,x,y;i<m;i++){
        cin >> x >> y;
        dis[x][y].dis = 0;
        q.push({x,y});
    }

    for(int i=0,count;i<k;i++){
        cin >> ord[i].x >> ord[i].y >> count;
        ord[i].count+=count;
    }

    for(int i=0,x,y;i<d;i++){
        cin >> x >> y;
        dis[x][y].type = -1;
    }

    bfs();

    for(int i=0;i<k;i++){
        ans+=dis[ord[i].x][ord[i].y].dis*(long long)ord[i].count;
    }

    cout << ans;
}