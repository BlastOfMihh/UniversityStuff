#include <bits/stdc++.h>
#define db(x) if(0)cerr<<#x<<":"<<x<<"  "
#define sz(x) int((x).size())
using namespace std;

ifstream fin("g.in");
ofstream fout("g.out");
#define cin fin
#define cout fout

char s[1000000];
const string fsay="what does the fox say?";

void solve(){
    vector<string> words;
    cin.get();
    auto splitWords=[&](){
        memset(s,0, sizeof s);
        cin.getline(s, 1000000);
        for(char *p=strtok(s," "); p; p=strtok(0," ")){
            string w;
            for(int i=0; p[i]; ++i)
                w.push_back(p[i]);
            words.push_back(w);
        }
    };
    splitWords();
    unordered_set<string> st;
    db("\nnew")<<"\n";
    while(true){
        string animal, goes, sound;
        cin>>animal>>goes>>sound;
        db(animal);
        db(goes);
        db(sound)<<"\n";
        if(goes=="does"){
            db(fsay);
            string s;
            cin>>s>>s;
            break;
        }
        st.insert(sound);
    }
    for(string &w:words){
        if (!(st.find(w)!=st.end())){
            cout<<w<<" ";
        }
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // flushes cout
    int t; cin>>t;
    while(t--){
        solve();
    }
}
