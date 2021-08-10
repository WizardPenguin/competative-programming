#include <bits/stdc++.h>
 
#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
 
void solve() {
    int n;
    string s;
    cin >> n >> s;
    set<string> se;
    // generating all substrings of size = 1-4 of input string
    for(int i=0;i<n;i++) {
        string ss;
        for(int k = 0; k < 4 && i + k < n; k++) {
            ss.push_back(s[i + k]);
            se.insert(ss);
        }
    }
    string tp= "#";
    bool found = false; 
    for(int i='a';i<='z';i++){
        tp[0] = i;
        if(se.find(tp) == se.end()){
            cout<<tp<<endl; 
            found = true; break; 
        }
    }
    tp = "##";
    if(!found)
    for(int i='a';i<='z';i++){
        tp[0] = i; 
        for(int j='a';j<='z';j++){
            tp[1] = j; 
            if(se.find(tp) == se.end()){
                cout<<tp<<endl; 
                found = true; break; 
            } 
        }
        if(found) break;
    }
    tp = "###";
    if(!found)
    for(int i='a';i<='z';i++){
        tp[0] = i; 
        for(int j='a';j<='z';j++){
            tp[1] = j; 
            for(int k='a';k<='z';k++){
                tp[2] = k; 
                if(se.find(tp) == se.end()){
                    cout<<tp<<endl; 
                    found = true; break; 
                }
            }
            if(found) break;
        }
        if(found) break; 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}