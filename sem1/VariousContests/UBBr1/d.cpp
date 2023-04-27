#include<bits/stdc++.h>
#define db(x) cerr<<#x<<":"<<x<<" "
using namespace std;

const int N=503;
#define float double

struct dp{
    float v=1e9;
    vector<int> team;
    dp(){
        v=1e9;
        team.resize(5);
    }
} bst[N][2][5];

void solve(){
    int n; cin>>n;
    vector<float> a(n+1,0), b(n+1,0);
    vector<string> names(n+1,string());
    for(int i=1;i<=n;++i){
        cin>>names[i];
        cin>>a[i]; cin>>b[i];
    }
    for(int i=1;i<=n;++i){
        // db(names[i]); db(a[i]); db(b[i])<<"\n";
        cin>>names[i];
        cin>>a[i]; cin>>b[i];
    }
    bst[0][0][0].v=0;
    for(int i=1;i<=n;++i){
        for(int f:{0,1}){
            bst[i][0][0].v=0;
            for(int nr=0;nr<=3;++nr){  // ceilalti 3
                if(f==1){
                    bst[i][1][nr].team=bst[i-1][1][nr].team;
                    bst[i][1][nr].v=bst[i-1][1][nr].v;
                    if(nr>0 and bst[i][1][nr].v>bst[i-1][1][nr-1].v+b[i]){
                        bst[i][1][nr].v=bst[i-1][1][nr-1].v+b[i];
                        bst[i][1][nr].team=bst[i-1][1][nr-1].team;
                        bst[i][1][nr].team[nr]=i;
                    }
                    if(bst[i][1][nr].v>bst[i-1][0][nr].v+a[i]){
                        bst[i][1][nr].v=bst[i-1][0][nr].v+a[i];
                        bst[i][1][nr].team=bst[i-1][0][nr].team;
                        bst[i][1][nr].team[0]=i;
                    }
                }else{ // f==0
                    bst[i][0][nr].team=bst[i-1][0][nr].team;
                    bst[i][0][nr].v=bst[i-1][0][nr].v;
                    if(nr>0 and bst[i][0][nr].v>bst[i-1][0][nr-1].v+b[i]){
                        bst[i][0][nr].v=bst[i-1][0][nr-1].v+b[i];
                        bst[i][0][nr].team=bst[i-1][0][nr-1].team;
                        bst[i][0][nr].team[nr]=i;
                    }
                }
            }
        }
    }
    // cout<<fixed<<setprecision(2)<<
        cout<<bst[n][1][3].v<<"\n";
    // cout<<fixed<<setprecision(4)<<bst[n][1][3].v<<"\n";
    for(int i=0;i<=3;++i)
        // cout<<i<<" "<< bst[n][1][3].team[i]<<" " <<
            cout<<names[bst[n][1][3].team[i]]<<"\n";
}

int main(){
    // if(0)
    {
        freopen("d.in", "r", stdin);
        freopen("d.out", "w", stdout);
    }
    solve();
}
