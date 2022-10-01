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
#define MOD 1000000007
vector<int> pall; 
int crt(int I, int b, bool io){
	int n = I;
	int p = I;
	if (io) n /= b;
	while (n){
		p = p * b + (n % b);
		n /= b;
	}
	return p;
}
void find(int n){
	for (int j = 0; j < 2; j++){
		int i = 1;
		while(true){
            int formed = crt(i, 10, j % 2); 
            if(formed > n){
                break; 
            }
            pall.push_back(formed); 
			i++;
		}
	}
}
// map<pii,int> dp; 
// int recursive(int n,int i){
//     if(n < 0) return 0;  // exact number not foun d
//     if(n == 0) return 1; 
//     if(i == pall.size()) return 0;  // all pall iterated 
//     if(pall[i] > n) return 0; // pall is larger no more possibilities
//     if(dp.find({n,i}) != dp.end()) return dp[{n,i}]; 
//     // generate by taking some occurences
//     // either take same previous number 
//     // or take new number 
//     int ret = recursive(n - pall[i],i) + recursive(n,i+1);
//     return dp[{n,i}] = ret;
// }
vector<vector<int> > dp(40004,vector<int>(500,0)); 
void solve(){
    int n; 
    cin>>n; 
    cout<<dp[n][pall.size()-1]<<endl; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    find(40001); 
    sort(pall.begin(),pall.end());
    for(int i=0;i<pall.size();i+=1){
        dp[0][i] = 1; 
    }
    for(int i=1;i<=40002;i+=1){
        for(int p=0;p<pall.size();p+=1){
            // cerr<<"p"<<p<<" "; 
            if(pall[p] <= i){
                dp[i][p] += dp[i-pall[p]][p];
                if(p){
                    dp[i][p] += dp[i][p-1]; 
                }
            }
            else{
                dp[i][p] = dp[i][p-1]; // make same value using previous pallindromes only 
            }
            dp[i][p] %= MOD; 
        }
    }
    while(test--){
        solve();
    }
    return 0;
}