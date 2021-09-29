// at max each number is going to get logx(a[i]) steps for each number 
// so we can have NlongN complexity 
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
        int n; 
        cin>>n; 
        vector<int> v(n); 
        int x; 
        cin>>x; 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        } 
        // let's go round and round 
        // first if number divisible then add v[i] to sum , replace numbers with prev/x initial values are same a v
        // if not break procedure   
        // at max it cound go to have 32 round log2(10^9) so it won't cause tle 
        long long sum = 0; 
        vector<int> tp = v;
        while (true)
        {
            int i=0;
            bool repeat = true; 
            for(i=0;i<n;i++){
                if(tp[i]%x == 0){
                    sum += v[i]; 
                    tp[i]/=x; 
                }
                else{
                    repeat = false; 
                    break; 
                }
            }
            if(!repeat){
                // then add remaining numbers as it is and break; 
                for(int i=0;i<n;i++){
                    sum += v[i]; 
                }
                break; 
            }
        }
        cout<<sum<<endl; 
    }
    return 0;
}