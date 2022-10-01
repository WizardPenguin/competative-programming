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
    int n; 
    cin>>n; 
    vi m,j; 
    int val; 
    for(int i=0;i<n;i+=1){
        cin>>val; 
        if(i&1){
            j.push_back(val);
        }
        else{
            m.push_back(val); 
        }
    }
    if(n&1){
        cout<<"Mike"<<endl; 
        return; 
    }
    int mmi = min_element(all(m)) - m.begin(); 
    int jmi = min_element(all(j)) - j.begin(); 
    // cerr<<mmi<<" "<<jmi<<endl; 
    if(m[mmi] == j[jmi]){
        if(mmi == jmi){
            cout<<"Joe"<<endl; 
        }
        else if(mmi > jmi){
            cout<<"Mike"<<endl; 
        }
        else  cout<<"Joe"<<endl; 
    }
    else{
        if(m[mmi] > j[jmi]){
            cout<<"Mike"<<endl; 
        }
        else{
            cout<<"Joe"<<endl; 
        }
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