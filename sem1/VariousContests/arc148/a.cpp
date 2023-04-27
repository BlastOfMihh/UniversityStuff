#include<bits/stdc++.h>
using namespace std;

int cmmdc(int x, int y){
    if(y==0) return x;
    return cmmdc(y, x%y);
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a.begin()+1, a.end());
    for(int i=2;i<=n;++i){
        a[i]-=a[1];
    }
    auto getCm=[&](){
        int cm=a[2];
        for(int i=3; i<=n; ++i){
            cm=cmmdc(a[i], cm);
        }
        return cm;
    };
    if(getCm()!=1){
        cout<<1;
    } else cout<<2;
}

int main(){
    solve();
}
