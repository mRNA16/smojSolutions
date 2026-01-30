#include <cstdio>
#include <queue>
using namespace std;

int r,c;
int sym[55][55],sr[55][55],tr[55][55];

struct node {
    int x;
    int y;
    node() {}
    node(int dx,int dy):x(dx),y(dy){}
    static bool valid(node a){
        return (a.x<r)&&(a.y<c)&&(a.x>=0)&&(a.y>=0);
    }

    static bool trap(node a){
        return sym[a.x][a.y]==1;
    }

    static bool ws(node a,node b){
        return a.x+1==b.x||a.x-1==b.x;
    }

    static bool ad(node a,node b){
        return a.y+1==b.y||a.y-1==b.y;
    }

    static bool s(node a,node b){
        return a.x+1==b.x;
    }

    static bool reach(node a,node b,int mode){
        if(!valid(b)) return false;
        if(trap(b)) return false;
        if(mode) return reach(b,a,0);
        return (sym[a.x][a.y]==2&&(ws(a,b)||(ad(a,b))))||
        (sym[a.x][a.y]==3&&((ad(a,b))))||
        (sym[a.x][a.y]==4&&((ws(a,b))))||
        (sym[a.x][a.y]==5&&((s(a,b))))||
        (sym[a.x][a.y]==6&&((ws(a,b)||ad(a,b))))||
        (sym[a.x][a.y]==7&&((ws(a,b)||ad(a,b))));
    }
} s,t;

void bfs(int mode){
    int (*reach)[55] = (mode)?tr:sr;
    node& n = (mode)?t:s;
    queue<node> q;
    q.push(n);
    reach[n.x][n.y] = 1;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while(!q.empty()){
        node u = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = u.x+dx[i];
            int ny = u.y+dy[i];
            node nei(nx,ny);
            if(node::valid(nei)&&reach[nx][ny]==0){
                if(node::reach(u,nei,mode)){
                    q.push(nei);
                    reach[nx][ny] = 1;
                }
            }
        }
    }
}

int main(){
    scanf("%d %d\n",&r,&c);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            switch (getchar())
            {
            case '#':
                sym[i][j] = 1;
                break;
            case '+':
                sym[i][j] = 2;
                break;
            case '-':
                sym[i][j] = 3;
                break;
            case '|':
                sym[i][j] = 4;
                break;
            case '.':
                sym[i][j] = 5;
                break;
            case 'S':
                sym[i][j] = 6;
                s.x=i,s.y=j;
                break;
            case 'T':
                sym[i][j] = 7;
                t.x=i,t.y=j;
                break;
            default:
                break;
            }
        }
        getchar();
    }

    bfs(0);
    if(sr[t.x][t.y]!=1) {
        printf("I'm stuck!\n");
        return 0;
    }
    bfs(1);

    int ans = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(sr[i][j]==1&&tr[i][j]!=1) ans++;
        }
    }

    printf("%d\n",ans);
    return 0;
}