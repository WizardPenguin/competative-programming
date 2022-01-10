// we need to store how many have frequency >= 4 and how many can be paired to make ractangle 
// so if we have >= 2 square good
// or 1 square and >= 4 paired nodes  since 2 pairs are used by 1 sqaure
// otherwise NO
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
    map<int,int> mp; 
    int val; 
    int four = 0; 
    int two = 0; 
    for(int i=0;i<n;i++){
        cin>>val; 
        mp[val] = mp[val] + 1; 
        if(mp[val]%4 == 0){
            four += 1; 
        }
        if(mp[val]%2 == 0){
            // means adding this occurence it have became even means we have two pair
            two ++; 
        }
    }
    int q; 
    cin>>q; 
    char t; 
    int v; 
    while(q--){
        cin>>t>>v; 
        if(t == '+'){
            // need to add new value 
            mp[v] = mp[v] + 1; 
            if(mp[v]%4 == 0){
                four += 1; 
            }
            if(mp[v]%2 == 0){
                // means adding this occurence it have became even means we have two pair
                two ++; 
            }
        }
        else{
            mp[v]--;
            if(mp[v]%4 == 3){
                /// this 4 is going to break
                four--; 
            }
            if(mp[v]%2 == 1){
                // it was even and now have been converted to odd 
                two--; 
            } 
        }
        if(four == 1 and two >= 4){
            cout<<"YES"<<endl; 
        }
        else if(four > 1){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl; 
        }
    }
    
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}