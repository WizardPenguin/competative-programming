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
vector<string> arr; 
vector<int> pallindrome; 
void solve(){
    string startTime; 
    cin>>startTime; 
    int offset; 
    cin>>offset; 
    int lb = lower_bound(all(arr),startTime) - arr.begin(); 
    // cerr<<lb<<endl; 
    vector<bool> visited(arr.size(),false); 
    int ans = 0; 
    while(not visited[lb]){
        visited[lb] = true; 
        ans += pallindrome[lb];
        lb += offset;  
        lb %= arr.size(); 
    }
    cout<<ans<<endl; 
}
bool isPall(string s){
    int i=0; 
    int j = s.length() -1; 
    while(i<j){
        if(s[i] != s[j]) return false; 
        i+=1,j-=1; 
    }
    return true; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    for(int h=0;h<24;h+=1){
        string hours = to_string(h); 
        if(hours.size() == 1){
            hours = "0" + hours; 
        }
        for(int m=0;m<60;m+=1){
            string minutes = to_string(m); 
            if(minutes.size() == 1){
                minutes = "0" + minutes; 
            }
            arr.push_back(hours + ":" + minutes); 
            pallindrome.push_back(isPall(arr.back())); 
        }
    }
    // cerr<<arr.size()<<endl; 
    // cerr<<pallindrome.size()<<endl; 
    // now finding repetation by finding time's index
    while(test--){
        solve();
    }
    return 0;
}