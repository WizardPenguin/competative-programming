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
    vs v(n); 
    for(int i=0;i<n;i++) cin>>v[i];
    map<string,int> mp; 
    set<string> st; 
    for(int i=0;i<n;i++){
        auto &s = v[i]; 
        if(mp[s]) mp[s] ++; 
        else mp[s] = 1; 
        st.insert(s); 
    }
    // considering creation using substrings before it 
    auto backup = mp; 
    set<string> before; 
    for(int i=0;i<n;i++){
        auto s = v[i]; 
        // remove element from remaining list of string on right side 
        mp[s] -= 1; 
        if(s.length() == 3){
            // find all len = 2 subsequences before it 
            if(s[0] != s[1]) continue; 
            for(auto &tp: before){
                auto formed = tp; 
                formed += s[0]; 
                reverse(all(formed)); 
                if(mp[formed]){
                    cout<<"YES"<<endl; 
                    return; 
                }
            }
            auto tp = s.substr(0,2);
            reverse(all(tp)); 
            if(mp[tp]){
                cout<<"YES"<<endl; 
                return; 
            } 
        }
        else if(s.length() == 2){
            for(auto &tp: before){
                auto formed = tp; 
                formed += s[0]; 
                reverse(all(formed)); 
                if(mp[formed]){
                    cout<<"YES"<<endl; 
                    return; 
                }
            }
            before.insert(s); // len 2 which are going to be appended
        }
        
    }
    // now from ending 
    mp = backup; 
    set<string> after; 
    for(int i=n-1;i>=0;i--){
        auto &s = v[i]; 
        mp[s] -= 1; 
        if(mp[s] == 0){
            mp.erase(s); 
        }
        if(s.length() == 3){
            // find all len = 2 subsequences before it 
            if(s[1] != s[2]) continue;
            if(after.size()) 
            for(auto &tp: after){
                auto formed = tp; 
                formed += s.back(); 
                reverse(all(formed)); 
                if(mp[formed]){
                    cout<<"YES"<<endl; 
                    return; 
                }
            }
            auto tp = s.substr(1); 
            reverse(all(tp)); 
            if(mp[tp]){
                cout<<"YES"<<endl; 
                return; 
            }
        }
        else if(s.length() == 2){
            for(auto &tp: after){
                auto formed = tp; 
                formed += s.back(); 
                reverse(all(formed)); 
                if(mp[formed]){
                    cout<<"YES"<<endl; 
                    return; 
                }
            }
            after.insert(s); // len 2 which are going to be appended
        }
        reverse(all(s)); 
        if(st.find(s) != st.end()){
            cout<<"YES"<<endl; 
            return; 
        }
    }
    cout<<"NO"<<endl; 
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