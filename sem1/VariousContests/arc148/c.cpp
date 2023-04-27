#include<bits/stdc++.h>
#define db(x) if(0)cerr<<setw(2)<<#x<<":"<<x<<"  "
using namespace std;

const int N=1e6+10;
int n;
int p[N];
int kids[N];

void solve(){
    int m; cin>>m;
    set<int> dark;
    for(int i=1;i<=m;++i){
        int v; cin>>v;
        dark.insert(v);
    }
    int ans=0;
    for(int x : dark){
        db(ans);
        ans+=kids[x]+1;
        db(x);
        if(dark.find(::p[x])!=dark.end()){
            ans--;
            ans--;
            db("found");
        }
        db(ans)<<"\n";
    }
    cout<<ans<<"\n";
}

int main(){
    freopen("g.in", "r",stdin);
    freopen("g.out", "w",stdout);
    cin>>n;
    int q; cin>>q;
    for(int i=2;i<=n;++i){
        cin>>p[i];
        // g[i].push_back(p[i]);
        // kids[p[i]].push_back(i);
        kids[p[i]]++;
    }
    // q=1;
    while(q--)
        solve();
}
