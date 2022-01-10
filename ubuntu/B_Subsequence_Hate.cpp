// try to make subsequence in for 11111.....0000 or 00000....11 , where some part might be null, like no zeros or no ones
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
    int n = s.length(); 
    // count all zeros and ones 
    // while triversing remove it from right side count of zeros and ones 
    // and add it to count of zeros and ones on left side 
    // for each index find how many inversions required to make this array in form given above
    pii end = {0,0}; 
    for(int i=0;i<n;i++){
        if(s[i] == '1'){
            end.first ++; 
        }
        else{
            end.second++; 
        }
    }
    // cout<<end.first<<" "<<end.second<<endl; 
    pii start = {0,0} ;
    int ans = min(end.first,end.second); // case when whole array changed to either 1 or 0 
    for(int i=0;i<n;i++){
        // remove this from end
        if(s[i] == '1'){
            end.first--;
            start.first++;  
        }
        else{
            end.second--; 
            start.second++; 
        }
        // cout<<start.first<<" "<<start.second<<"    "; 
        // cout<<end.first<<" "<<end.second<<endl; 
        // splitting at this index left side be all 0's or 1's
        ans = min(ans,end.first + start.second); 
        ans = min(ans,end.second + start.first); 
    }
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