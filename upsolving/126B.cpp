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
#define MOD 1000000007
#define P 37
int n; 
bool check(string &s,int mid){
    cout<<"ASKED AT "<<mid<<endl; 
    // substring check takes O(n^2), so we required rabin carp algorithm to check it's validity
    // we are using prime multiple as 37
    ll mapping = 0; 
    ll p = 1;  
    for(int i=0;i<mid;i+=1){
        if(s[i] != s[n - mid + i]) return false;
        mapping += (s[i] - ' ')*p; 
        p*= P; 
        p%= MOD; 
        mapping %= MOD;
    }
    // cout<<"possible at "<<mid<<endl;
    int i; ll currMapping = 0;p = 1; 
    for(i=n-mid-1;i<n-1;i+=1){
        // cout<<s[i]<<" "; 
        currMapping += (s[i] - ' ')*p; 
        mapping%= MOD; 
        if(i == n-2) break;  
        p*=P; 
        p%=MOD; 
    }
    // now new element is added with power 1 and previous element is removed with previous power 
    if(currMapping == mapping) return true; 
    i = n - mid - 2; 
    while(i>0){
        currMapping -= (s[i+mid] - ' ')*p; 
        currMapping *= P; 
        currMapping %= MOD; 
        currMapping += MOD + (s[i] - ' ');
        currMapping %= MOD; 
        if(currMapping == mapping){
            // check it again 
            bool found = true; 
            for(int j=0;j<mid;j+=1){
                if(s[i+j] != s[n-mid+j]){
                    found = false; 
                    break; 
                }
            }
            if(found) return true; 
        }
        i-=1; 
    }
    return false; 
}

void solve(){
    string s; 
    cin>>s; 
    n = s.length(); 
    // binary search on solution length 
    int left = 0; 
    int right = n-1; // complete length can't be solution 
    // if we found some valid point we need to increase length 
    // otherwise we need to decrease length 
    while(left < right){
        int mid = (left + right+1)/2;
        if(check(s,mid)){
            left = mid; 
        }
        else{
            right = mid-1; 
        }
    } 
    if(left == 0){
        cout<<"Just a legend"<<endl; 
    }
    else{
        cout<<s.substr(0,left)<<endl; 
    }
}
int main(){
    fast_cin();
    ll test;
    test = 1; 
    while(test--){
        solve();
    }
    return 0;
}