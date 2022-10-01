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
    int n,k; 
    cin>>n>>k;
    // cerr<<n<<k<<endl;  
    vll v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    // count each reminders 
    ll ans = 0,count = 0; 
    vector<ll> cnt(k); 
    for(auto &elm: v){
        cnt[elm%k] += 1; 
        ans += elm/k; 
    }
    cnt[0] = 0; 
    for(int i=0;i<k;i+=1) count += cnt[i]; 
    int id = 0; 
    for(int i=k-1;i>=(k + 1)/2; i-=1){
        ll itself = cnt[i]; 
        count -= (cnt[k-i-1] + itself);
        if(count < 0){
            itself += count; 
            cout<<ans + itself/2<<endl; 
            return;
        }
        if(count >= itself){
            count -= itself;  
            ans += itself;
            for(int j=max(id,k-i);j<i;j+=1){
                id = j;
                if(cnt[j] > itself){
                    cnt[j] -= itself; 
                    break; 
                }
                else{
                    itself -= cnt[j]; 
                    cnt[j] = 0; 
                }
            }
        }
        else{
            // it takes all remaining + coubines with itself 
            ans += count;
            itself -= count;  
            ans += itself/2; 
            break; 
        } 
    }
    // cerr<<endl; 
    cout<<ans<<endl; 
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