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
        string s; 
        cin>>s; 
        // cout<<s<<endl; 
        bool found = false; 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a,b; 
                a = b = 0; 
                for(int x = i; x <=j;x++){
                    if(s[x] == 'a') a++; 
                    else if(s[x] == 'b') b++; 
                }
                if(a == b){
                    cout<<i + 1<<" "<<j + 1<<endl; 
                    found = true; 
                    goto end; 
                }
            }
        }
        end:
        if(!found){
            cout<<-1<<" "<<-1<<endl; 
        }
    }
    return 0;
}