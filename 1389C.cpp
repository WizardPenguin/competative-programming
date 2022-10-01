#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
    // finally we can have ababab.. types string 
    // or we can have all same aaaa... types string 
    // iterate over all possibilities and find largest one 
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
#define N 10
#define log(x) cerr<<x<<endl; 
void solve(){
    string s; 
    cin>>s; 
    vvi ids(N); 
    for(int i=0;i<s.length();i+=1){
        ids[s[i] - '0'].push_back(i); 
    }
    int maxLen = 0; 
    for(int i=0;i<N;i+=1){
        auto &vi = ids[i]; 
        for(int j=0;j<N;j+=1){
            auto &vj = ids[j]; 
            int index = -1; 
            bool ithTern = true; 
            int lena = 0,lenb = 0; 
            while(true){  // first find for i then find for j  
                if(ithTern){
                    int lb = upper_bound(vi.begin(),vi.end(),index) - vi.begin(); 
                    // cerr<<lb<<" i "<<i<<endl; 
                    if(lb >= vi.size()) break; 
                    index = vi[lb]; 
                    lena += 1; 
                }
                else{
                    int lb = upper_bound(vj.begin(),vj.end(),index) - vj.begin(); 
                    // cerr<<lb<<" j "<<j<<endl; 
                    if(lb >= vj.size()) break; 
                    index = vj[lb]; 
                    lenb += 1; 
                }
                ithTern = !ithTern; 
            } // till we are having next occurence of element we can do this work 
            if(i == j){
                maxLen = max(maxLen,lena + lenb); 
            }
            else{
                maxLen = max(maxLen,2*min(lena,lenb)); 
            }
        }
    }
    cout<<s.length() - maxLen<<endl; 
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