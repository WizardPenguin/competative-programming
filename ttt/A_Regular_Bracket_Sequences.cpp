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
int x,n ;
int cnt = 0; 
void generateBrackets(string s,int left,int right){
    if(cnt > x) return;  
    if(left == 0 and right == 0){
        cnt++; 
        cout<<s<<endl; 
        return; 
    }
    if(left != 0){
        generateBrackets(s + "(",left -1,right); 
    }
    if(cnt > x) return; 
    if(left < right){
        generateBrackets(s + ")",left ,right -1); 
    }
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        cin>>n; 
        x = n; 
        cnt = 1; 
        generateBrackets("",n,n); 
    }
    return 0;
}