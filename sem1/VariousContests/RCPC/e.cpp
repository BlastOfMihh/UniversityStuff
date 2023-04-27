#include <bits/stdc++.h>
#define print(x) if(0)cerr<<#x<<":"<<x<<"  "
using namespace std;


vector<char> diffs({'x','y','z','w'});
char get_diff(char a, char b){
    for (char c:diffs){
        if(c!=a and c!=b) return c;
    }
    return '?';
}


void solve(){
    int n, d; cin>>n>>d;
    string a, b; cin>>a>>b;
    a=" "+a, b=" "+b;
    string c(n+1,'?');
    vector<int> ind_diff, ind_equal;
    for(int i=1;i<=n;++i){
        if(a[i]!=b[i]){
            ind_diff.push_back(i);
        }else {
            ind_equal.push_back(i);
        }
        c[i]=get_diff(a[i], b[i]);
    }
    int q=ind_diff.size();
    if (d<q-q/2){
        cout<<"-1";
        return ;
    }
    int cnt=n;
    for(int i=0; i+1<q and d<cnt; i+=2){
        print(i)<<"\n";
        int ind=ind_diff[i];
        int next_ind=ind_diff[i+1];
        print(ind); print(next_ind);
        c[ind]=a[ind];
        c[next_ind]=b[next_ind];
        cnt--;
        if(cnt==d) break;
    }
    for(int ind:ind_equal){
        if(!(cnt>d)) break;
        cnt--;
        c[ind]=a[ind];
    }
    print("hello");
    for (int i = 1; i <= n; ++i)
        cout << c[i];
}

int32_t main(){
    // freopen("e.in", "r", stdin);
    // freopen("e.out", "w", stdout);
    solve();
}
