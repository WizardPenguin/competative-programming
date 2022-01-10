/// using construction we need repetation of a given sequence of size k to make every subseqnce of size k having same sum 
// for then if we are having == k elements we are good to go 
// otherwise we are required to make array of distinct elements are add some number to make it of size k 
// after then repeat it atlest n times so that repetative elements have came into array with >= their repetations
// also since we are having repetation of list of size k we are shurely going to have condition of problem met
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
    set<int> st; 
    int val; 
    for(int i=0;i<n;i++){
        cin>>val; 
        st.insert(val);
    }
    vi v; 
    for(auto &i: st) v.push_back(i); 
    if(v.size() > k){
        cout<<-1<<endl;
    }
    else{
        while(v.size() < k) v.push_back(1); 
        cout<<n
        
        *k<<endl; 
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
                cout<<v[j]<<" "; 
            }
        }
        cout<<endl; 
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