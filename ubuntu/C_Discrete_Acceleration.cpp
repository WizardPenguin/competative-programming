// from both side find who takes minimum time to reach next accelerating station 
// make that one to reach there and more other one accordingly 
// after then when all satations are taken find time when they meets 
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
#define e 1e-8
void solve(){
    ll n,l; 
    cin>>n>>l; 
    vi v(n); 
    for(int i=0;i<n;i++){
        cin>>v[i]; 
    }
    double s1 = 1; 
    double s2 = 1; 
    double d1 = 0; 
    double d2 = l; 
    double time = 0; 
    int i=0; 
    int j = n-1; 
    while(i<=j){
        double t1 = (v[i] - d1)/s1; 
        double t2 = (d2 - v[j])/s2;
        if(abs(t1-t2) <= e){
            time += t1; 
            s1 += 1; 
            s2 += 1;  
            d1 = v[i]; 
            d2 = v[j]; 
            i++,j--;
        } 
        else if(t1 < t2){
            // make 1st to reach flag causing it's speed to increase 
            time += t1; 
            s1 += 1; 
            d1 = v[i]; 
            d2 -= (t1)*s2;  // reach where it can reach after t1 time 
            i++;
        }
        else{
            time += t2; 
            s2 += 1; 
            d2 = v[j]; 
            d1 += (t2)*s1; 
            j--;
        }
    }
    // now find meeting time 
    double d = d2 - d1; 
    double s = s1 + s2; 
    cout<<fixed; 
    cout<<setprecision(15); 
    time += (d)/s; 
    cout<<time<<endl; 
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