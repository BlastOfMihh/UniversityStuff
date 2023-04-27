#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
#define print(x) cerr<<#x<<":"<<x<<"  "
#include <fstream>
using namespace std;

ifstream fin("g.in");
ofstream fout("g.out");

const int N=105;
char a[N][N];

#define x first
#define y second
#define pii pair<int,int>

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

int n;
pair<int,int> pPac;
int maxMoves;
int nrCoins=0;

int leeM[N][N];

int dx[]={-1,1, 0,0};
int dy[]={0,0, -1,1};

bool goodPos(pii p, int leeM[N][N]){
    return a[p.x][p.y]!='W' and a[p.x][p.y]!='G' and leeM[p.x][p.y]==0;
}

char get_inverse(char chr)
{
    if (chr == 'L') return 'R';
    if (chr == 'R') return 'L';
    if (chr == 'D') return 'U';
    return 'D';
}

void lee(pii cPos, pii &nPos, int leeM[N][N]){
    queue<pii> q({cPos});
    int minDist=INT_MAX;
    leeM[cPos.x][cPos.y]=1;
    while(q.size()){
        pii curr=q.front();
        q.pop();
        if (a[curr.x][curr.y]=='C' and leeM[curr.x][curr.y]<minDist){
            minDist=leeM[curr.x][curr.y];
            nPos=curr;
        }
        for (int i=0; i<4; ++i){
            pii nextPos={curr.x+dx[i], curr.y+dy[i]};
            if(goodPos(nextPos, leeM)){
                leeM[nextPos.x][nextPos.y]=leeM[curr.x][curr.y]+1;
                q.push(nextPos);
            }
        }
    }
    if (minDist==INT_MAX){
        nPos={-1,-1};
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

void add_step(pii curr, pii target, int leeM[N][N], string& sol){
    string curr_steps;
    while(curr!=target){
        pii prev=curr;
        for (int i=0; i<4; ++i){
            pii nextPos={curr.x+dx[i], curr.y+dy[i]};
            if (leeM[nextPos.x][nextPos.y]+1==leeM[curr.x][curr.y]){
                curr=nextPos;
                break;
            }
        }
        print(curr.x);
        print(curr.y)<<"\n";
        curr_steps+=getLetter(prev,curr);
    }
    print(curr_steps)<<"\n";
    string res_cur_steps;
    for (auto it = curr_steps.rbegin(); it != curr_steps.rend(); ++it)
    {
        res_cur_steps.push_back((*it));
    }
    // reverse(curr_steps.begin(), curr_steps.end());
    sol.append(res_cur_steps);
}

void solve(){
    pair<int,int> nPos, cPos;
    cPos=pPac;
    // vector<pair<int,int>> sol;
    string sol;
    while(true){
        memset(leeM, 0, sizeof leeM);
        lee(cPos, nPos, leeM);
        if(nPos==make_pair(-1,-1))
            break;
        a[nPos.x][nPos.y]='?';
        add_step(nPos, cPos, leeM, sol);
        cPos=nPos;
        print(cPos.x);
        print(cPos.y)<<"\n";
    }
    fout<<sol;
}

int main(){
    fin>>n;
    for(int i=1;i<=n;++i){
        fin>>(a[i]+1);
    }
    fin>>pPac.x>>pPac.y;
    fin>>maxMoves;
    solve();
}
