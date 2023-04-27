#include <bits/stdc++.h>
#define db(x) cerr<<#x<<":"<<x<<"  "
#define sz(x) int((x).size())
using namespace std;

ifstream fin("b.in");
ofstream fout("b.out");
#define cin fin
#define cout fout


void solve(int t){
    int n; cin>>n;
    vector<int> a(n+2,0);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    auto fa = [&]() {
      for (int i = 1; i <= n; ++i)
        cout << a[i] << " ";
      cout << '\n';
    };
    // fa();
    for(int i=1; i<=n; ++i){
        int pi=i;
        for(;a[i]>a[i+1];++i)
            ;
        if(i>=n) --i;
        // db(pi); db(i)<<'\n';
        sort(a.begin()+pi, a.begin()+i+1);
    }
    bool ok=true;
    // fa();
    for(int i=1;i<=n;++i){
        if(a[i]!=a[i-1]+1) {
            ok=false;
            break;
        }
    }
    if(ok ) cout<<"Not a proof";
    else cout<<"Cheater";
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // flushes cout
    solve(1);
}
