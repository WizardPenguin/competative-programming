// we are only required to check weather inequality holds or not
// for largest value we need to check any +ve number should have -ve antitode for it
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
    vi v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    int maxi = max_element(all(v)) - v.begin(); 
    // move from max element towards all it's nbr and any +ve found should have -ve to overcome it 
    if(v[maxi] <= 0){
        cout<<"YES"<<endl; 
        return; 
    }
    ll left = maxi,right = maxi, leftSum = 0, rightSum = 0; 
    while(left - 1 >= 0){
        while(left - 1 >= 0 and v[left-1] < 0){
            leftSum += v[left-1]; 
            left -= 1; 
        }
        // now we have left-1 as +ve or we are done 
        if(left-1 >=0 and v[left-1] > abs(leftSum)){
            cout<<"NO"<<endl;
            return; 
        }
        left -= 1; 
        leftSum = 0; 
    }
    while(right + 1 < n){
        while(right + 1 < n and v[right + 1] < 0){
            rightSum += v[right+1]; 
            right += 1; 
        }
        if(right + 1 < n and v[right + 1] > abs(rightSum)){
            cout<<"NO"<<endl; 
            return; 
        }
        right += 1; 
        rightSum = 0; 
    }
    cout<<"YES"<<endl; 
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