#include <bits/stdc++.h>
#define print(x) cerr<<#x<<":"<<x<<"  "
#include <fstream>
using namespace std;

ifstream fin("g.in");
ofstream fout("g.out");

const int N=105;
char a[N][N];

#define x first
#define y second

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

int nrGhosts=0;
string movesGhost[N*N];
pair<int,int> pGhost[N*N];


int main(){
    int n; fin>>n;
    int nrCoins=0;
    for(int i=1;i<=n;++i){
        fin>>(a[i]+1);
    }
    pair<int,int> pPac; fin>>pPac.x>>pPac.y;
    int moveN; fin>>moveN;
    string movesPac;
    fin>>movesPac;
    // for(char c : movesP){
    //     if (a[p1][p2]=='C'){
    //         nrCoins++;
    //         a[p1][p2]=')';
    //     }
    // }
    fin>>nrGhosts;
    for(int i=1;i<=nrGhosts; ++i){
        fin>>pGhost[i].x>>pGhost[i].y;
        fin>>moveN;
        fin>>movesGhost[i];
    }
    print(movesPac);
    for (int step=1;step<=moveN;++step){
        step--;
        for (int i=1; i<=nrGhosts; ++i){
            update_coords(pGhost[i], movesGhost[i][step]);
            if(pPac==pGhost[i]){
              fout << nrCoins << " NO";
              return 0;
            }
        }
        if (a[pPac.x][pPac.y]=='W'){
            fout<<nrCoins<<" NO";
            return 0;
        }
        if (a[pPac.x][pPac.y]=='C'){
            ++nrCoins;
            a[pPac.x][pPac.y]='0';
        }
        step++;
    }
    fout<<nrCoins<<" YES";
}
