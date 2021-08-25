// we can make such tree and give depth of each node 
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
vector<int> d; 
vector<int> v; 
void makeTree(int start,int end,int depth){
    if(start > end) return ;
    if(start == end){
        d[start] = depth;  
        return; 
    }
    // find max value and make it's height as this call's height 
    int elm = max_element(v.begin() + start,v.begin() + end + 1) - v.begin(); 
    d[elm] = depth; 
    makeTree(start,elm-1,depth+1); 
    makeTree(elm+1,end,depth+1); 
}

int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; 
        cin>>n; 
        v = vector<int>(n); 
        for(int i=0;i<n;i++) cin>>v[i];
        // cout<<"make Tree"<<endl;  
        d = vector<int>(n,0); 
        makeTree(0,n-1,0); 
        for(auto i: d){
            cout<<i<<" "; 
        }
        cout<<endl; 
    }
    return 0;
}