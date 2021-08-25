// at any point make one team win all then make other team win remaining if it coudn't win from there we found soln
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
#define N 10
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        vector<int> v(N,0); 
        string s; cin>>s;
        bool found = false; 
        int first,second,odd,even; 
        first = second = odd = even = 0; 
        // first is storing necessary goal's for first team to make 
        // odd is '?' count for first team that might be converted to find goals 
        for(int i=0;i<N;i++){
            if((i&1)){
                if(s[i] == '1'){
                    first++;  
                }
                else if(s[i] == '?'){
                    odd++; 
                } 
            }
            else{
                if(s[i] == '1'){
                    second++;
                }
                else if(s[i] == '?'){
                    even++; 
                }
            }
            // cout<<first<<" "<<odd<<" "<<second<<" "<<even<<endl; 
            // now considering one as winning all it's goal then other team will win all remaining whatever array is
            int n = N - i -1; 
            int o = n/2 + (n&1); 
            int e = n/2;
            if(first + odd > second + e){
                found = true; 
                cout<<(i+1)<<endl; 
                break; 
            } 
            if(even + second > first + o){
                found = true; 
                cout<<(i+1)<<endl; 
                break; 
            }
        }
        if(!found) cout<<N<<endl; 
    }
    return 0;
}