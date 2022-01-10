// if we try to have painting in reverse order 
// if painter he color which is not required by nonmaching elements then we can give it to already matched element
// otherwise we can give it to one which is just painted correctly since that node is surely going to painted again with correct color
// so once we have found first color which goes to it's correct position we needn't to worry about invalid colors
// at end need to check weather all nonmatching nodes are painted 
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
    int n,m; 
    cin>>n>>m; 
    n++; 
    vi p(n),np(n); 
    for(int i=1;i<n;i++) cin>>p[i]; 
    for(int i=1;i<n;i++) cin>>np[i]; 
    vi q;
    int qi;  
    for(int i=0;i<m;i++){
        cin>>qi; 
        q.push_back(qi); 
    }
    reverse(all(q)); 
    // now let's paint cells 
    // before that let's separate all non matching cells 
    vvi v(n);
    map<int,int> waiste;  
    for(int i=1;i<n;i++){
        if(np[i] != p[i]) v[np[i]].push_back(i); // ith index need np[i] color painting 
        else{
            waiste[np[i]] = i; 
        }
    }
    int gwaiste = -1; 
    bool found = true; 
    vi res; 
    for(int i=0;i<m;i++){
        qi = q[i]; 
        if(v[qi].size()){
            // paint a cell 
            gwaiste = v[qi].back(); 
            waiste[gwaiste] = v[qi].back(); 
            v[qi].pop_back();
        }
        else if(gwaiste == -1){
            // means we have only choice to paint cell with same color as qi 
            if(waiste.find(qi) == waiste.end()){
                found = false; 
                break; 
            }
            else{
                gwaiste = waiste[qi]; 
            }
        }
        res.push_back(gwaiste); 
    }
    if(found){
        for(int i=1;i<n;i++){
            if(v[i].size()){
                found = false; break; 
            }
        }
    }
    reverse(all(res)); 
    if(found){
        cout<<"YES"<<endl; 
        for(auto &i: res){
            cout<<i<<" "; 
        }
        cout<<endl; 
    }
    else{
        cout<<"NO"<<endl; 
    }
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