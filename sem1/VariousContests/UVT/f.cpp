#include<bits/stdc++.h>
#define db(x) cerr<<#x<<" "<<x<<"  "
using namespace std;

ifstream fin("f.in");
ofstream fout("f.out");
#define cin fin
#define cout fout

const int INF=1e9;

void solve(){
    int n, m ,q;
    cin>>n>>m>>q;
    vector<vector<int>> a(n+1, vector<int>(m+1,0));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            cin>>a[i][j];
    }
    vector<int> bst(1<<n,INF);
    vector<int> sols(n+1,INF);
    bst[0]=0;
    // for(int s=1; s<(1<<n);++s){
        // for(int x=0; x<n; ++x)
        //     if(s&(1<<x)){
        //         int posSol=0;
        //         for(int j=1;j<=m;++j){
        //             for(int y=0; y<n; ++y)
        //                 if(s&(1<<y)){
        //                     s=min()
        //                 }
        //         }
        //         bst[s]=min({
        //             bst[s],
        //         });
        //     }
    // }
    auto get_val=[&](int s)->int{
        int ans=0;
        for(int j=1;j<=m;++j){
            int lans=0;
            for(int x=1;x<=n;++x){
                if(s&(1<<(x-1))){
                    lans=max(lans, a[x][j]);
                }
            }
            ans+=lans;
        }
        return ans;
    };
    for(int s=1; s<(1<<n);++s){
        bst[s]=get_val(s);
        int nrBits=__builtin_popcount(s);
        sols[nrBits]=min(sols[nrBits], bst[s]);
    }
    for(int i=1;i<=q;++i){
        int tc; cin>>tc;
        // db(tc);
        cout<<sols[tc]<<"\n";
    }
    // cout<<"\n";
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
