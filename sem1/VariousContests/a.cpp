#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin>>n;
    multiset<int> a;
    for(int i=1;i<=n;++i){
        int x; cin>>x;
        a.insert(x);
    }
    int ans=0;
    while(a.size()>=1){
        ++ans;
        int mn=*a.begin(), mx=*a.rbegin();
        a.erase(--a.end());
        if(mx%mn!=0)
            a.insert(mx%mn);
    }
    cout<<ans-1;
}

int main(){
    solve();
}
