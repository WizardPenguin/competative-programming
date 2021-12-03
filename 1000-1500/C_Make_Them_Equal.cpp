#include <bits/stdc++.h> 
#include <complex>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())


int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        // we can check for each number fron 1..n weather they can be in solution 
        // this gives complexity n + n/2 + n/3 .... = NlongN
        int n; char c; 
        cin>>n>>c; 
        string s; 
        cin>>s; 
        s = " " + s; 
        bool found = true; 
        for(int i=1;i<=n;i++){
            if(s[i] != c){
                found = false; 
                break; 
            }
        }
        if(found){
            cout<<0<<endl; 
            continue;
        }
        for(int i=2;i<=n;i++){
            found = true; 
            for(int j=i;j<=n;j+=i){
                if(s[j] != c){
                    found = false; 
                    break; 
                }
            }
            if(found){
                cout<<1<<endl; 
                cout<<i<<endl; 
                goto end; 
            }
        }
        cout<<2<<endl; 
        cout<<n-1<<" "<<n<<endl; 
        end:;
    }
    return 0;
}