// find occurences of each number then partitions it's making of array 
// minimum partitions required is result 
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
        vector<vector<int> > v(n + 1); 
        int num; 
        int start,end; 
        for(int i=0;i<n;i++){
            cin>>num; 
            if(i == 0){
                start= num; 
            }
            if(i == n-1){
                end = num; 
            }
            // we are going to skip consecutive similar numbers 
            if(!v[num].empty()){
                auto &x = v[num].back(); 
                if(x == i-1){
                    x = i; 
                }
                else{
                    v[num].push_back(i); 
                }
            }
            else{
                v[num].push_back(i); 
            }
        }
        // now check front and back elements and find min partitions made 
        int mini = INT_MAX; 
        for(int i=1;i<=n;i++){
            if(v[i].size() == 0) continue; 
            auto &vec = v[i]; 
            int part = vec.size() + 1; 
            if(i == start ){
                part--; 
            }
            if(i == end){
                part--; 
            }
            mini = min(part,mini); 
        }
        cout<<mini<<endl; 
    }
    return 0;
}