// can be done by some sort of dp
// we need to find when x:y had occured previously , if it's there then we can split string in two ratios
// then total splits will be count of x:y 
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
#define _ " "
int gcd(int x,int y){
    if(x == 0) return y; 
    return gcd(y%x,x);
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; cin>>n; 
        string s; cin>>s; 
        int countD = 0; 
        int countK = 0; 
        map< pair<int,int >,int > count;  
        for(int i=0;i<n;i++){
            if(s[i] == 'D'){
                countD++; 
            }
            else{
                countK++; 
            }
            pair<int,int> temp; 
            if((countD == 0) or (countK == 0)){
                temp = {countD != 0,countK != 0};
            }
            else{
                int g=gcd(countD,countK);
                // dbg(g);
                temp = {countD/g,countK/g};
            }
            // for each prefix we need to find answer
            count[temp] +=1;
            cout<<count[temp]<<_; 
        }
        cout<<ln; 
    }
    return 0;
}