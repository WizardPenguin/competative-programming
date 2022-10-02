#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<bool> > vvb;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 

void solve(){
    string s; 
    cin>>s; 
    int n; 
    n = s.length(); 
    vpii points;
    set<pii> choices;  
    pii start = {0,0}; 
    for(int i=0;i<n;i++){
        if(s[i] == 'R'){
            start.first += 1; 
        }
        else if(s[i] == 'L'){
            start.first -= 1; 
        }
        else if(s[i] == 'U'){
            start.second += 1; 
        }
        else{
            start.second-=1; 
        }
        choices.insert(start); 
    }
    for(auto &ch: choices){
        start = {0,0}; 
        for(int i=0;i<n;i++){
            auto tp = start; 
            if(s[i] == 'R'){
                start.first++; 
            }
            else if(s[i] == 'L'){
                start.first--; 
            }
            else if(s[i] == 'U'){
                start.second++; 
            }   
            else{
                start.second--; 
            }
            if(start == ch){
                start = tp; // reverse the move since we have obstacle on nesxt move
            }
        }
        if(start.first == 0 and start.second == 0){
            cout<<ch.first<<" "<<ch.second<<endl; 
            return; 
        }
    }
    cout<<0<<" "<<0<<endl; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}