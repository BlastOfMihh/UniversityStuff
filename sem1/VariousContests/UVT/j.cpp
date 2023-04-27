#include<bits/stdc++.h>
#define db(x) cerr<<#x<<" "<<x<<"  "
using namespace std;

ifstream fin("j.in");
ofstream fout("j.out");
// #define cin fin
// #define cout fout

#define int unsigned long long

vector<int> ans;

void divide(int l, int r){
    if (ans.size()>=(1<<10)) return;
    if(l>r) return;
    cout<<"q "<<l<<' '<<r<<endl;
    int nr; cin>>nr;
    int mid=(l+r)/2;
    if(nr==(r-l+1)){ // we found a whole interval of 1s
        for(int i=l; i<=r; ++i)
            ans.push_back(i);
        return ;
    }
    if(nr!=0){
        divide(l,mid);
        divide(mid+1, r);
    }
}

void solve(){

    // for(int i=0; i<=(1<<17)+3; ++i){
    //     cout<<"q 1 1"<<endl;
    //     int x; cin>>x;
    // }
    // cout<<"a 0 0"<<flush;
    // return ;
    const int LMAX=(1ull<<63);
    if(1){
        divide(0,LMAX-1);
    }else {
        const int base=4;
        divide(0,0);
        for(int exp=1; exp<=LMAX/2; exp*=base){
            int nexp=min(exp*base, LMAX);
            divide(exp-1, nexp-1);
        }
        divide(LMAX/base-1, LMAX-1);
        sort(ans.begin(), ans.end());
        // cout<<9223372036854775807<<"\n";
        // cout<<((1ull<<63)-1ull)<<'\n';
        // return ;
    }
    cout<<"a "<<ans.size()<<" ";
    for(int x:ans)
        cout<<x<<" ";
    cout<<flush;
}

int32_t main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    solve();
}
