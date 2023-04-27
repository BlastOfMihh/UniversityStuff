#include <bits/stdc++.h>
#define db(x) if(0)cerr<<#x<<":"<<x<<"  "
#define sz(x) int((x).size())
using namespace std;

ifstream fin("e.in");
ofstream fout("e.out");
#define cin fin
#define cout fout


void solve(int t){
    long long n;
    cin>>n;
    if(n%10==0){
        cout<<2;
    }else{
        cout<<1<<"\n"<<n%10;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // flushes cout
    solve(1);
}
