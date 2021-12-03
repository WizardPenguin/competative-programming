// when size even then make pari of two and multiply then with such number that their product sum = 0
// if odd then make pair of 2 except last pair of size 3 
// for size 3 ai,aj,ak
// we can multiply with ak,ak,-(ai + aj) given that ai,aj are having same sign otherwise their sum might = 0
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
        vector<int> v(n),id; 
        for(int i=0;i<n;i++) cin>>v[i],id.push_back(i); 
        sort(all(id),[&](const int &a,const int &b){
            return v[a]<v[b]; 
        });
        vector<int> b(n); 
        if(n&1){
            int start = 0; 
            int end = n-1; 
            if(v[id[0]] + v[id[1]] != 0){
                start =3; 
                b[id[0]] = b[id[1]] = -v[id[2]];
                b[id[2]] = v[id[0]] + v[id[1]]; 
            }
            else{
                b[id[n-3]] = v[id[n-2]] + v[id[n-1]]; 
                b[id[n-2]] = b[id[n-1]] = -v[id[n-3]]; 
                end = n-4; 
            }
            for(int i=start;i<=end;i+=2){
                b[id[i]] = - v[id[i+1]]; 
                b[id[i+1]] = v[id[i]]; 
            }
        }
        else{
            for(int i=0;i<n;i+=2){
                b[id[i]] = -v[id[i+1]]; 
                b[id[i+1]] = v[id[i]]; 
            }
        }
        for(auto &x: b) cout<<x<<" "; cout<<endl; 
    }
    return 0;
}