#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class loc {
    private:
        int x;
        int y;

    public:
        loc():x(-1),y(-1){}
        loc(int x,int y){
            this->x = x;
            this->y = y;
        }
        int getX(){
            return x;
        }
        int getY(){
            return y;
        }
};
class bar {
    private:
        loc loc1;
        loc loc2;
        // 0为站立，1为横躺，2为竖躺
        int lay;
        int step;

    public:
        bar() {
            this->loc1 = loc();
            this->loc2 = loc();
            this->lay = 0;
            this->step = 0;
        }

        bar(loc l,int step) {
            loc1 = l;
            loc2 = loc();
            lay = 0;
            this->step = step;
        }

        bar(loc loc1,loc loc2,int step) {
            this->loc1 = loc1;
            this->loc2 = loc2;
            if(loc2.getX()==loc1.getX()){
                lay = 1;
            } else if(loc2.getY()==loc1.getY()){
                lay = 2;
            } else {
                lay = 0;
            }
            this->step = step;
        }

        loc getLoc1() {
            return this->loc1;
        }
        loc getLoc2() {
            return this->loc2;
        }
        int getLay() {
            return this->lay;
        }
        int getStep() {
            return this->step;
        }

        void init(loc loc) {
            if(this->loc1.getX() ==-1) {
                this->loc1 = loc;
            } else {
                this->loc2 = loc;
                if(loc2.getX()==loc1.getX()){
                    lay = 1;
                } else if(loc2.getY()==loc1.getY()){
                    lay = 2;
                }
            }
            this->step = 0;
        }

        bar up(bool* ok,int n,int m) {
            switch(lay) {
                // 站立
                case 0: {
                    int y = getLoc1().getY();
                    int x = getLoc1().getX();
                    if(x-2<0) *ok = false;
                    else *ok = true;
                    bar new_bar(loc(x-1,y),loc(x-2,y),getStep()+1);
                    return new_bar;
                }
                // 横躺
                case 1:{
                    int x = getLoc1().getX();
                    int y1 = getLoc1().getY();
                    int y2 = getLoc2().getY();
                    if(x-1<0) *ok = false;
                    else *ok = true;
                    bar new_bar(loc(x-1,y1),loc(x-1,y2),getStep()+1);
                    return new_bar;
                }
                    
                // 竖躺
                case 2:{
                    int x1 = getLoc1().getX();
                    int x2 = getLoc2().getX();
                    int min_x = min(x1,x2);
                    int y = getLoc1().getY();
                    if(min_x-1<0) *ok = false;
                    else *ok = true;
                    bar new_bar(loc(min_x-1,y),getStep()+1);
                    return new_bar;
                }
                default:
                    return *this;
            }
        }

        bar down(bool* ok,int n,int m) {
            switch(lay) {
                // 站立
                case 0:{
                    int y = getLoc1().getY();
                    int x = getLoc1().getX();
                    if(x+2>=n) *ok = false;
                    else *ok = true;
                    bar new_bar(loc(x+1,y),loc(x+2,y),getStep()+1);
                    return new_bar;
                }
                    
                // 横躺
                case 1:{
                    int x = getLoc1().getX();
                    int y1 = getLoc1().getY();
                    int y2 = getLoc2().getY();
                    if(x+1>=n) *ok = false;
                    else *ok = true;
                    bar new_bar(loc(x+1,y1),loc(x+1,y2),getStep()+1);
                    return new_bar;
                }
                    
                // 竖躺
                case 2:{
                    int x1 = getLoc1().getX();
                    int x2 = getLoc2().getX();
                    int max_x = max(x1,x2);
                    int y = getLoc1().getY();
                    if(max_x+1>=n) *ok = false;
                    else *ok = true;
                    bar new_bar(loc(max_x+1,y),getStep()+1);
                    return new_bar;
                }
                default:
                    return *this;
            }
        }

        bar left(bool* ok,int n,int m) {
            switch(lay) {
                // 站立
                case 0:{
                    int y = getLoc1().getY();
                    int x = getLoc1().getX();
                    if(y-2<0) *ok = false;
                    else *ok = true;
                    bar new_bar(loc(x,y-1),loc(x,y-2),getStep()+1);
                    return new_bar;
                }
                    
                // 横躺
                case 1:{
                    int x = getLoc1().getX();
                    int y1 = getLoc1().getY();
                    int y2 = getLoc2().getY();
                    int min_y = min(y1,y2);
                    if(min_y-1<0) *ok = false;
                    else *ok = true;
                    bar new_bar(loc(x,min_y-1),getStep()+1);
                    return new_bar;
                }
                    
                // 竖躺
                case 2:{
                    int x1 = getLoc1().getX();
                    int x2 = getLoc2().getX();
                    int y = getLoc1().getY();
                    if(y-1<0) *ok = false;
                    else *ok = true;
                    bar new_bar(loc(x1,y-1),loc(x2,y-1),getStep()+1);
                    return new_bar;
                }
                default:
                    return *this;
            }
        }

        bar right(bool* ok,int n,int m) {
            switch(lay) {
                // 站立
                case 0:{
                    int y = getLoc1().getY();
                    int x = getLoc1().getX();
                    if(y+2>=m) *ok = false;
                    else *ok = true;
                    bar new_bar(loc(x,y+1),loc(x,y+2),getStep()+1);
                    return new_bar;
                }
                    
                // 横躺
                case 1:{
                    int x = getLoc1().getX();
                    int y1 = getLoc1().getY();
                    int y2 = getLoc2().getY();
                    int max_y = max(y1,y2);
                    if(max_y+1>=m) *ok = false;
                    else *ok = true;
                    bar new_bar(loc(x,max_y+1),getStep()+1);
                    return new_bar;
                }
                    
                // 竖躺
                case 2:{
                    int x1 = getLoc1().getX();
                    int x2 = getLoc2().getX();
                    int y = getLoc1().getY();
                    if(y+1>=m) *ok = false;
                    else *ok = true;
                    bar new_bar(loc(x1,y+1),loc(x2,y+1),getStep()+1);
                    return new_bar;
                }
                default:
                    return *this;
            }
        }
};

enum Type {
    blank,ground,glass
};

class floor{
    private:
        int x;
        int y;
        Type type;

    public:
        floor(){
            this->x = -1;
            this->y = -1;
            this->type = blank;
        }
        floor(int x,int y,Type type){
            this->x = x;
            this->y = y;
            this->type = type;
        }
        Type getType() {
            return this->type;
        }
        int getX() {
            return this->x;
        }
        int getY() {
            return this->y;
        }
};

bool isValid(bar& b,vector< vector<floor> >& playgroud){
    loc l1 = b.getLoc1();
    loc l2 = b.getLoc2();
    int lay = b.getLay();

    auto check = [&](loc L){
        int x = L.getX(), y = L.getY();
        if(x<0 || y<0) return false;
        if(x>=playgroud.size() || y>=playgroud[0].size()) return false;
        if(playgroud[x][y].getType() == Type::blank) return false;
        return true;
    };

    if(lay == 0){ // 站立必须落在 ground
        if(playgroud[l1.getX()][l1.getY()].getType() != Type::ground)
            return false;
    }

    if(lay == 1 || lay == 2){
        if(!check(l1) || !check(l2)) return false;
    }
    return true;
}

bool checkIsReach(bar& b,int& t_x,int& t_y){
    if(b.getLay()==0&&b.getLoc1().getX() == t_x && b.getLoc1().getY() == t_y) {
        return true;
    }
    return false;
}

struct StateKey {
    int x, y, lay;
};

// 将 bar 状态归一化为唯一 key
StateKey normalize(bar& b) {
    loc l1 = b.getLoc1();
    loc l2 = b.getLoc2();
    int lay = b.getLay();

    if (lay == 0) {
        // 站立时 l1 == l2
        return {l1.getX(), l1.getY(), 0};
    }

    if (lay == 1) {
        // 横躺（x 相同，按 y 排序）
        if (l1.getY() <= l2.getY())
            return {l1.getX(), l1.getY(), 1};
        else
            return {l2.getX(), l2.getY(), 1};
    }

    if (lay == 2) {
        // 竖躺（y 相同，按 x 排序）
        if (l1.getX() <= l2.getX())
            return {l1.getX(), l1.getY(), 2};
        else
            return {l2.getX(), l2.getY(), 2};
    }

    // 不可能
    return {l1.getX(), l1.getY(), lay};
}

int main(){
    int t;
    cin >> t;
    while(t > 0) {
        int n,m;
        cin >> n >> m;
        vector< vector<floor> > playGround(n, vector<floor>(m));
        bar b;
        int t_x,t_y;
        queue<bar> q;
        bool visited[505][505][3] = {};
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c;
                cin >> c;
                switch (c)
                {
                case '#':{
                    playGround[i][j] = floor(i,j,Type::blank);
                    break;
                }
                    
                case '.':{
                    playGround[i][j] = floor(i,j,Type::ground);
                    break;
                }
                    
                case 'E':{
                    playGround[i][j] = floor(i,j,Type::glass);
                    break;
                }
                    
                case 'X':{
                    playGround[i][j] = floor(i,j,Type::ground);
                    b.init(loc(i,j));
                    break;
                }
                    
                case 'O':{
                    playGround[i][j] = floor(i,j,Type::ground);
                    t_x = i;
                    t_y = j;
                    break;
                }
                    
                default:
                    break;
                }
            }
        }

        q.push(b);
        while(q.size() > 0) {
            bool ok;
            bar now_b = q.front();
            q.pop();
            bar up = now_b.up(&ok,n,m);
            if(checkIsReach(up,t_x,t_y)) {
                cout << up.getStep() << "\n";
                flag = true;
                break;
            }
            if(ok) {
                StateKey key = normalize(up);
                if(!visited[key.x][key.y][key.lay]&&isValid(up,playGround)){
                    visited[key.x][key.y][key.lay] = true;
                    q.push(up);
                } 
            }
            



            bar down = now_b.down(&ok,n,m);
            if(checkIsReach(down,t_x,t_y)) {
                cout << down.getStep() << "\n";
                flag = true;
                break;
            }
            if (ok){
                StateKey key = normalize(down);
                if(!visited[key.x][key.y][key.lay]&&isValid(down,playGround)){
                    visited[key.x][key.y][key.lay] = true;
                    q.push(down);
                } 
            }
            



            bar left = now_b.left(&ok,n,m);
            if(checkIsReach(left,t_x,t_y)) {
                cout << left.getStep() << "\n";
                flag = true;
                break;
            }
            if(ok) {
                StateKey key = normalize(left);
                if(!visited[key.x][key.y][key.lay]&&isValid(left,playGround)){
                    visited[key.x][key.y][key.lay] = true;
                    q.push(left);
                } 
            }
            

            bar right = now_b.right(&ok,n,m);
            if(checkIsReach(right,t_x,t_y)) {
                cout << right.getStep() << "\n";
                flag = true;
                break;
            }
            if(ok) {
                StateKey key = normalize(right);
                if(!visited[key.x][key.y][key.lay]&&isValid(right,playGround)){
                    visited[key.x][key.y][key.lay] = true;
                    q.push(right);
                }
            }
            
        }
        if(!flag) cout << -1 << "\n";
        t--;
    }
    return 0;
}