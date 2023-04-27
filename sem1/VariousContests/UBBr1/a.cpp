#include<bits/stdc++.h>
#define db(x) cerr<<#x<<":"<<x<<"  "
using namespace std;

const int N=1e6+4;

#define int long long

void solve(){
    int st, dr;
    cin>>st>>dr;
    if(dr<=40){
        cout<<dr*2+st;
    }else{
        cout<<40*2+st+(dr-40);
    }
}


int32_t main(){
    // if(0)
    {
        freopen("a.in", "r", stdin);
        freopen("a.out", "w", stdout);
    }
    solve();
}
