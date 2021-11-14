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
        // either found "aa"
        // or "aba"
        // or "aca"
        int n; 
        cin>>n; 
        string s; 
        cin>>s; 
        // auto f1 = s.find("aa"); 
        // auto f2 = s.find("aba"); 
        // auto f3 = s.find("aca"); 
        if(s.find("aa") != string::npos){
            cout<<2<<endl; 
        }
        else if((s.find("aba") != string::npos) or (s.find("aca") != string::npos)){
            cout<<3<<endl; 
        }
        else if(s.find("abca") != string::npos or s.find("acba") != string::npos){
            cout<<4<<endl; 
        }
        else if(s.find("abbacca") != string::npos or s.find("accabba") != string::npos){
            cout<<7<<endl; 
        }
        else{
            cout<<-1<<endl;
        }
    }
    return 0;
}