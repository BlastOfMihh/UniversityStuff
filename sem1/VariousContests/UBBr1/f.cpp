#include<iostream>
#include<vector>
#include<memory>
#include<climits>
#include<bitset>
#include<cstring>
#define db(x) cerr<<#x<<":"<<x<<" "
using namespace std;

int n,m, c1, c2;
const int N=504;
char a[N][N];
bool viz[N][N];

int d1[4]={-1,1,0,0};
int d2[4]={-1,1,0,0};

vector<pair<int,int > > vp;

int add(int x, int y){
    int ans=0;
    // for(pair<int,int> p:vp){
    for(int i=0; i<4;++i){
        pair<int,int> p=vp[i];
        int nx=p.first+x, ny=p.second+y;
        if (a[nx][ny]=='.') ans+=1;
    }
    return ans;
}

int dfs(int x, int y){
    int ans=0;
    ans+=add(x,y);
    viz[x][y]=1;
    for(int i=0;i<4; ++i){
        int l=d1[i];
        for(int j=0; j<4; ++j){
            int c=d2[j];
            int nx=l+x, ny=c+y;
            if(a[nx][ny]=='X' and viz[nx][ny]==0){
                ans+=dfs(nx, ny);
                viz[nx][ny]=1;
            }
        }
    }
    return ans;
}

void solve(){
    memset(a, '.', sizeof a);
    memset(viz, 0, sizeof a);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            cin >> a[i][j];
    }
    cout << dfs(c1, c2)<<"\n";
}

int main(){
    vp.push_back(make_pair(-1,0));
    vp.push_back(make_pair(0,-1));
    vp.push_back(make_pair(1,0));
    vp.push_back(make_pair(0,1));
    // if(0)
    {
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
    }
    while (true){
        cin>>n>>m>>c1>>c2;
        if(n==0 and m==0 and c1==0 and c2==0)
            break;
        solve();
    }
}
