#include <bits/stdc++.h>
#define db(x) if(0)cerr<<#x<<":"<<x<<"  "
#define sz(x) int((x).size())
using namespace std;

ifstream fin("h.in");
ofstream fout("h.out");
#define cin fin
#define cout fout


void solve(int t){
    int n; cin>>n;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int minBar=a[1], goodI=a[1];
    for(int i=2;i<=n;++i){
        if(i<=goodI)
            minBar=goodI=a[i];
        else if(a[i]<=minBar) ++minBar;
    }
    cout<<"Case "<<t<<": "<<minBar<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // flushes cout
    int t; cin>>t;
    for(int i=1; t--; ++i){
        solve(i);
    }
}
