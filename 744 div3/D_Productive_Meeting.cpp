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
        priority_queue<pair<int,int> > q; 
        for(int i=0;i<n;i++){
            int num; cin>>num; 
            if(num)
            q.push({num,i}); 
        }
        vector<pair<int,int> > ans; 
        // cout<<q.size()<<endl; 
        // int count =0; 
        while(q.size() >=2){
            auto a = q.top(); 
            q.pop(); 
            auto b = q.top(); q.pop(); 
            ans.push_back({a.second,b.second});
            a.first--; 
            b.first--; 
            if(a.first){
                q.push(a); 
            }
            if(b.first){
                q.push(b); 
            }
            // count++; 
            // if(count >= 10) break; 
        }
        cout<<ans.size()<<endl;
        for(auto i: ans){
            cout<<i.first + 1<<" "<<i.second + 1<<endl; 
        }
    }
    return 0;
}