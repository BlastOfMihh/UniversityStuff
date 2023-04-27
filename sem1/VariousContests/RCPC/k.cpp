#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n, d;
    cin>>n>>d;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    vector<vector<int>> sp(d);
    for(int i=1;i<=n;++i){
        sp[i%d].push_back(a[i]);
    }
    for(int j=1; j<=d; ++j){
        sort(sp[j-1].begin(), sp[j-1].end());
    }
    vector<int> as;
    for(int i=0;i<=n/d; ++i){
        for(int j=1; j<=d; ++j){
            if(j==d){
                j=0;
            }
            if(i>=sp[j].size()) break;
            as.push_back(sp[j][i]);
            if(j==0)
                j=d;
        }
    }
    bool ok=1;
    for(int i=1;i<n;++i){
        if (as[i]<as[i-1]) ok=0;
    }
    if (ok)
        cout<<"YES";
    else cout<<"NO";
}

int main(){
    solve();
}
