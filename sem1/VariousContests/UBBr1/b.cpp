#include<bits/stdc++.h>
#define db(x) cerr<<#x<<":"<<x<<"  "
using namespace std;

const int N=1e6+4;

#define int long long

int n;
int target;
int len=0;
int a[N];

int sum(int l){
    int ans=0;
    for(int i=1;i<=n;++i){
        if(a[i]>=l)
            ans+=a[i]-l;
        else break;
    }
    return ans;
}

int BS(int lx, int ly){
    int bl=0;
    while(lx<=ly){
        int mid=(lx+ly)/2;
        int sm=sum(mid);
        if(sm>=target){
            bl=max(bl, mid);
            lx=mid+1;
        }else{ // sm<target
            ly=mid-1;
        }
    }
    return bl;
}

void solve(){
    cin>>n;
    cin >>target;
    int lmax=0;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        lmax=max(a[i], lmax);
    }
    sort(a+1, a+1+n, std::greater<int>());
    int ans=BS(0,lmax);
    cout<<ans;
    // db(target);
    // db(sum(36));
    // db(sum(ans));
}

int32_t main(){
    if(0)
    {
        freopen("b.in", "r", stdin);
        freopen("b.out", "w", stdout);
    }
    solve();
}
