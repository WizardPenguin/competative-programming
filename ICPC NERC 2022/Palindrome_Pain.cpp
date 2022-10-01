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
    if((n == 1 or m == 1) or ((n&1) and (m&1))){
        cout<<-1<<endl; 
    }
    else{
        if((n&1) or (m&1)){
            char mid = (n&1)?'a': 'b'; 
            n = n/2; m = m/2; 
            string formed; 
            formed += 'a'; 
            formed += 'b'; 
            m-=1; 
            n-=1; 
            for(int i=0;i<n;i+=1){
                formed += 'a'; 
            }
            for(int i=0;i<m;i+=1){
                formed += 'b'; 
            }
            string reversed = formed; 
            reverse(reversed.begin(),reversed.end()); 
            string s1 = formed + mid + reversed; 
            swap(formed[0],formed[1]); 
            reversed = formed; 
            reverse(reversed.begin(),reversed.end()); 
            string s2 = formed + mid + reversed; 
            cout<<s1<<endl; 
            cout<<s2<<endl; 
        }
        else{
            string formed;
            formed += 'a'; 
            formed += 'b'; 
            n/=2; 
            n-=1; 
            m/=2; 
            m-=1;  
            for(int i=0;i<n;i+=1){
                formed += 'a'; 
            }
            for(int j=0;j<m;j+=1){
                formed += 'b'; 
            }
            string reversed = formed; 
            reverse(reversed.begin(),reversed.end()); 
            string s1 = formed + reversed; 
            swap(formed[0],formed[1]); 
            reversed = formed; 
            reverse(reversed.begin(),reversed.end()); 
            string s2 = formed + reversed; 
            cout<<s1<<endl; 
            cout<<s2<<endl; 
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