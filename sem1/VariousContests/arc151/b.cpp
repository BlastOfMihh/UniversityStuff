#include<bits/stdc++.h>
#define print(x) cerr<<#x<<":"<<x<<"  "
using namespace std;

#define int long long

const int MOD= 998244353;

int pw(int x, int y){
    if(y==0) return 1;
    int sq=pw(x,y/2);
    if(y%2) return (1ll*sq*sq*x)%MOD;
    return (1ll*sq*sq)%MOD;
}

int sub(int x, int y){
    return (1ll*MOD+x-y)%MOD;
}

void solve(){
    int n; cin>>n;
    int m; cin>>m;
    vector<int>p(n+1,0);
    vector<int>rp(n+1,0);
    for (int i=1;i<=n;++i){
        cin>>p[i];
        rp[p[i]]=i;
    }
    int c=0;
    vector<int>v(n+1,0);
    auto dfs=[&](int x, int color,auto dfs)->void{
        v[x]=color;
        if (v[p[x]]==0) {
            dfs(p[x], color, dfs);
        }
   };
    for (int i=1;i<=n;++i){
        if(v[i]==0)
            dfs(i,++c,dfs);
    }
    cout<<((sub(pw(m,n), pw(m, c)) + MOD)/2)%MOD;
}

int32_t main(){
    freopen("g.in", "r", stdin);
    freopen("g.out", "w", stdout);
    solve();
}
