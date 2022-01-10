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
int ask(int a,int b){
    cout<<"? "<<a + 1<<" "<<b + 1; 
    cout<<endl; 
    fflush(stdout); 
    int val; 
    cin>>val; 
    return val; 
}
void solve(){
    // try to find n and then we can find any number by taking modulo by it 
    // but finding n takes 2n steps since checking which number is greater takes 2 queries
    int n; 
    cin>>n; 
    // *** since after 2 comparisons we know which one is greater we also know value of smaller element precisely 
    // since if a>b then a%b < b and b%a == b
    vi res(n); 
    int previd = 0; 
    for(int i=1;i<n;i++){
        // now compare current and previd using modulo operations 
        int a = ask(previd,i); 
        int b = ask(i,previd); 
        if(a<b){
            // means previd has larger element and we have found value at i
            res[i] = b; 
        }
        else{
            // we have found value at previd 
            res[previd] = a; 
            previd = i; 
        }   
    }
    res[previd] = n; 
    cout<<"! "; 
    for(auto &i: res){
        cout<<i<<" "; 
    }
    fflush(stdout); 
}
int main(){
    // fast_cin();
    solve(); 
    return 0;
}