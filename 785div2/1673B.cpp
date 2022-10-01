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
    char ch = s[0]; 
    int n = s.length(); 
    set<int> st(s.begin(),s.end()); 
    // cerr<<st.size()<<endl;
    int window = st.size(); 
    for(int size=2;size<=window;size+=1){ 
        for(int i=0;i<n-size+1;i+=1){
            vector<int> freq(26,0);
            for(int offset = 0;offset<size;offset+=1){
                freq[s[i+offset] - 'a'] += 1;
                if(freq[s[i+offset] - 'a'] >= 2){
                    // cerr<<s[i+offset]<<" "<<size<<endl; 
                    cout<<"NO"<<endl; 
                    return; 
                }  
            }
        }
    }
    cout<<"YES"<<endl; 
    return; 
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