// replace all ? wherever it's necessary to make pallindrome also decrease count of 0 or 1 whenever found in way
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
        int a,b; cin>>b>>a; 
        string s; cin>>s; 
        int n = s.length(); 
        bool found = true; 
        for(int i=0;i<(n/2);i++){
            if(s[i] == s[n-i-1] and s[i] == '?') continue; 
            else{
                if(s[i] == '?') s[i] = s[n-i-1];
                else if(s[n-i-1] == '?')s[n-i-1] = s[i]; 
            }
            if(s[i] != s[n-i-1]){
                found = false; 
                break;
            }
            if(s[i] == '1' and a>=2) a -= 2; 
            else if(s[i] == '0' and b>=2) b -= 2;
            else{ found = false; break; }
        }
        // check middle element 
        if(n&1){
            if(s[n/2] != '?'){
                if(a and s[n/2] == '1') a--; 
                else if(b and s[n/2] == '0') b--; 
                else found = false; 
            }
        }
        if(found)
        for(int i=0;i<n/2;i++){
            if(s[i] == '?'){
                if( a >= 2 ){
                    a-=2;
                    s[i] = s[n-i-1] = '1'; 
                } 
                else if( b >= 2){
                    b -= 2; 
                    s[i] = s[n-i-1] = '0'; 
                } 
                else{
                    found = false;
                    break; 
                } 
            }
        }
        if(n&1){
            // then we have to check for middle element 
            if( s[n/2] == '?'){
                if(a){
                    s[n/2] = '1'; 
                    a-=1; 
                } 
                else if(b){
                    b-=1; 
                    s[n/2] = '0'; 
                }
                else found = false; 
            }
        }
        // cout<<a<<" "<<b<<endl; 
        if(found and a == 0 and b== 0){
            cout<<s<<endl; 
        }
        else{
            cout<<-1<<endl; 
        }
    }
    return 0;
}