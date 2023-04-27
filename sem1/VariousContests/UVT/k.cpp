#include <bits/stdc++.h>
#define db(x) cerr<<#x<<" "<<x<<"  "
using namespace std;

ifstream fin("k.in");
ofstream fout("k.out");
#define cin fin
#define cout fout

const int N=303;
int n, m;
char a[N][N];
bool viz[N][N];
typedef pair<int,int> pii;
#define x first
#define y second

bool isCorner(int i, int j){
    return a[i][j]=='+' and a[i][j]==a[i][j+1] and a[i+1][j]==a[i][j];
}

bool badLetter(char c){
    return !(isalpha(c) or c=='?' or c=='!' or c==',' or c=='.' or c==' ');
}

void whipe(pii c1, pii c2){
    for(int i=c1.x; i<=c2.x; ++i){
        for(int j=c1.y; j<=c2.y; ++j){
            viz[i][j]=1;
            a[i][j]=' ';
        }
    }
}

pii findOtherCorner(pii c1){
    pii c2={0,0};
    for(int i=c1.y;i<=m;++i){
        if (a[c1.x][i]!='+'){
            c2.y=i-1;
            break;
        }
    }
    for(int i=c1.x;i<=n;++i){
        if (a[i][c1.y]!='+'){
            c2.y=i-1;
            break;
        }
    }
    return c2;
}

void handleSquare(pii corner){
    pii otherCorner=findOtherCorner(corner);
    queue<pii> corners;
    queue<pii> q({{corner.x+1, corner.y+1}});// if empty image FIX //for the bfs
    viz[corner.x+1][corner.y+1]=1;
    db(otherCorner.x);
    db(otherCorner.y);
    // if(0)
    while(q.size()){
        db("x\n");
        pii curr=q.front();
        q.pop();
        if(viz[curr.x][curr.y]==0){
            if (a[curr.x][curr.y]=='+') {
                if(isCorner(curr.x, curr.y)){
                    corners.push(curr);
                }
            } else if (badLetter(a[curr.x][curr.y])){
                whipe(corner, otherCorner); // also do viz
                return ;
            }else{
                q.push(curr);
                viz[curr.x][curr.y]=1;
            }
        }
    }
    while(corners.size()){
        pii curr=corners.front();
        corners.pop();
        handleSquare(curr);
    }
}

void solve(){
    cin>>n>>m;
    cin.get();
    for(int i=1;i<=n;++i){
        cin.getline(a[i]+1, m+3);
    }
    for(int i=0;i<=n+1;++i){
        a[i][0]=a[i][m+1]='+';
        viz[i][0]=viz[i][m+1]='+';
    }
    for(int i=0;i<=m+1;++i){
        a[0][i]=a[n+1][i]='+';
        viz[0][i]=viz[n+1][i]=1;
    }
    // if(0)
    handleSquare({1,1});
    for(int i=0;i<=n+1;++i){
        for(int j=0;j<=m+1;++j){
            cout<<a[i][j];
        }
        cout<<"\n";
    }
    db(n); db(m);
    for(int i=0;i<=n+1;++i){
        for(int j=0;j<=m+1;++j){
            cerr<<viz[i][j];
        }
        cerr<<"\n";
    }
}

int main(){
    solve();
    cin.tie(0);
    cin.sync_with_stdio(0);
}
