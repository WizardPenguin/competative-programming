// let's try using binary seach 
// guess number of cheap spheres 
// then check weather we can make such combination that have that number of cheap sphere
// for that we are going to take largest number and take largest 2 numbers to cover it 
// we are going to take k largest number
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
bool check(vi &v,int id){
    if(id == 0) return true; 
    // from 0....i-1 we are going
    // assuming there are atlest 3 elements
    int i = id-1; 
    int j = v.size()-1;
    // make first step of taking this first number with 2 other number 
    if(v[j] > v[i] and v[j-1] > v[i]){ // assuming atlest 2 elements are there 
        // then we can take both elements for ith element 
        i--; 
        j--; // both elements taken 
        while(i>=0 and v[j] > v[i] and v[j-1] > v[i]){
            i--; 
            j--;
        }
        if(i < 0) return true; 
    }
    return false; 
}
void solve(){
    int n; 
    cin>>n; 
    vi v(n); 
    for(int i=0;i<n;i++) cin>>v[i]; 
    sort(all(v)); 
    int l = 0; 
    int r = (n-1)/2; 
    int ans = 0; 
    while(l<=r){
        int mid = (l + r)/2; 
        // check weather we can have mid number of peaks 
        if(check(v,mid)){
            // mid can be possible answer try finding larger one 
            ans = mid; 
            l = mid+1; 
        }
        else{
            r = mid-1; 
        }
    }
    // now create array that satisfies value at answer 
    // dbg(ans); 
    int i = ans-1; 
    int j = v.size() - 1; 
    vi res; 
    if(i>=0){
        res.push_back(v[j]); 
        res.push_back(v[i]); 
        res.push_back(v[j-1]); 
        i--; 
        j-=2; 
        while(i>=0){
            res.push_back(v[i]); 
            res.push_back(v[j]); 
            i--; 
            j--; 
        }
    }
    // now push remaining elements from side of j 
    while(j>=ans){
        res.push_back(v[j]); 
        j--;
    }
    cout<<ans<<endl; 
    for(auto &i: res) cout<<i<<" "; 
    cout<<endl; 
}
int main(){
    fast_cin();
    solve(); 
    return 0;
}