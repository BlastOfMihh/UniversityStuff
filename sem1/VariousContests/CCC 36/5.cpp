#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
#define print(x) if(0)cerr<<#x<<":"<<x<<"  "
#include <fstream>
using namespace std;

ifstream fin("g.in");
ofstream fout("g.out");

#define x first
#define y second
#define pii pair<int,int>

const int N=55;
char a[N][N];

int n;
pair<int,int> pPac;
int maxMoves;
int nrCoins=0;


int dx[]={-1,1, 0,0};
int dy[]={0,0, -1,1};

int nrGhosts;
string movesGhost[N*N];
pair<int,int> pGhost[N*N];

int len;

bool leeM[N][N][N*N];
bool ghostM[N][N][N*N];

pii coinPos;

void update_coords(pair<int,int> &p, char c){
  int &p1 = p.x, &p2 = p.y;
  switch (c) {
  case 'L':
    p2 += -1;
    break;
  case 'R':
    p2 += 1;
    break;
  case 'U':
    p1 -= 1;
    break;
  case 'D':
    p1 += 1;
    break;
  }
}

void ghost_process(){
    for (int step=0;step<len;++step){
        for (int i=1; i<=nrGhosts; ++i){
            update_coords(pGhost[i], movesGhost[i][step]);
            ghostM[pGhost[i].x][pGhost[i].y][step]=1;
        }
    }
}

bool goodPos(pii p, int t){
    return t<=50*len and ghostM[p.x][p.y][t%len]==0 and a[p.x][p.y]!='W' and leeM[p.x][p.y][t]==0; // added %len
}
void lee(){
    queue< pair<pii,int> > q({{pPac,0}});
    leeM[pPac.x][pPac.y][0]=1;
    while(q.size()){
        auto curr=q.front();
        pii currP=curr.first;
        int t=curr.second;
        q.pop();
        for (int i=0; i<4; ++i){
            pii nextP={currP.x+dx[i], currP.y+dy[i]};
            int nextT=t+1;
            if (goodPos(nextP, nextT)){
                q.push({nextP, nextT});
                leeM[nextP.x][nextP.y][nextT]=1;
            }
        }
    }
}

void set_coin_pos(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            if(a[i][j]=='C'){
                coinPos={i,j};
                return ;
            }
    }
}

char getLetter(pii prev, pii curr){

    if (prev.x<curr.x) return 'U';
    if (prev.x>curr.x) return 'D';

    if (prev.y<curr.y) return 'L';
     if (prev.y>curr.y) return 'R';
     return '?';

    if (prev.x<curr.x) return 'R';
    if (prev.x>curr.x) return 'L';

    if (prev.y<curr.y) return 'D';
     if (prev.y>curr.y) return 'U';
    //
    // if (prev.x<curr.x) return 'R';
    // if (prev.x>curr.x) return 'L';

    // if (prev.y<curr.y) return 'D';
    // if (prev.y>curr.y) return 'U';
    assert(false);
}

void add_step(pii curr, pii target, int t, string& sol){
    string curr_steps;
    while(curr!=target and t!=0){
        pii prev=curr;
        for (int i=0; i<4; ++i){
            pii nextPos={curr.x+dx[i], curr.y+dy[i]};
            if (leeM[nextPos.x][nextPos.y][t-1]){
                curr=nextPos;
                t--;
                break;
            }
        }
        print(curr.x);
        print(curr.y);
        print(t)<<"\n";
        curr_steps+=getLetter(prev,curr);
    }
    // print(curr_steps)<<"\n";
    string res_cur_steps;
    for (auto it = curr_steps.rbegin(); it != curr_steps.rend(); ++it)
    {
        res_cur_steps.push_back((*it));
    }
    // reverse(curr_steps.begin(), curr_steps.end());
    sol.append(res_cur_steps);
}

void solve(){
    set_coin_pos();
    ghost_process();
    lee();
    for(int i=1;i<=5*len; ++i){
        if (leeM[coinPos.x][coinPos.y][i]){
            string sol;
            add_step(coinPos, pPac, i, sol);
            fout<<sol;
            break;
        }
    }
}


char get_inverse(char chr) {
    if (chr == 'L') return 'R';
    if (chr == 'R') return 'L';
    if (chr == 'D') return 'U';
    return 'D';
}

int main(){
    fin>>n;
    for(int i=1;i<=n;++i){
        fin>>(a[i]+1);
    }
    fin>>pPac.x>>pPac.y;
    fin>>nrGhosts;
    for(int i=1;i<=nrGhosts; ++i){
        fin>>pGhost[i].x>>pGhost[i].y;
        fin>>len;
        fin>>movesGhost[i];
        string aux=movesGhost[i];
        reverse(aux.begin(), aux.end());
        for(char &c:aux){
            c=get_inverse(c);
        }
        // print(movesGhost[i])<<"\n";
        movesGhost[i].append(aux);
        // print(movesGhost[i])<<"\n\n";
    }
                // int cv; fin>>cv;
    len*=2;
    solve();
}
