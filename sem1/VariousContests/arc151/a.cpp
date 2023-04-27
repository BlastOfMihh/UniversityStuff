#include <bits/stdc++.h>
#define print(x) cerr<<#x<<":"<<x<<"  "
using namespace std;


void solve(){
    int n; cin>>n;
    string a,b;
    cin>>a;
    cin>>b;
    a=" "+a;
    b=" "+b;
    vector<int> sol(n+1,0);
    int tDiff=0;
    for(int i=1;i<=n;++i){
        if(a[i]!=b[i]) ++tDiff;
    }
    if(tDiff%2!=0){
        cout<<"-1";
        return ;
    }
    int eqA=0, eqB=0;
    for(int i=1;i<=n;++i){
        // print(i);
        // print(eqA);
        // print(eqB);
        if(a[i]==b[i]) sol[i]=0;
        else if(eqA<tDiff/2 and eqB<tDiff/2){
            // print("2");
            sol[i]=0;
            eqA+=(sol[i]==(a[i]-'0'));
            eqB+=(sol[i]==(b[i]-'0'));
        }else{
            if(eqA>eqB)
                sol[i]=b[i]-'0';
            else sol[i]=a[i]-'0';
        }
        // cerr<<"\n";
    }
    for(int i=1;i<=n;++i)
        cout<<sol[i];
}

int main(){
    freopen("g.in", "r", stdin);
    freopen("g.out", "w", stdout);
    solve();
}
