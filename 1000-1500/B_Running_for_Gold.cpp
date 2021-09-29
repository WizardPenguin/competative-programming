// for each index x find from how many it's superior and remove those peoples from graph 
// now choose other index if it's superior than y and the check with remaining 
// eventually try find which is superior than all 
// we need to find one which is superios to all peoples 
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

bool superior(vector<int>&a,vector<int> &b){
    int count =0;
    for(int i=0;i<5;i++){
        if(a[i] < b[i]){
            count++; 
        }
    }
    return count > 2;
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; 
        cin>>n; 
        vector<vector<int> > v(n,vector<int>(5)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>v[i][j];
            }
        }
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i] = i; 
        }
        sort(all(res),[&](const auto &x,const auto &j){
            auto &a = v[x]; 
            auto &b = v[j];
            int count =0;
            for(int i=0;i<5;i++){
                if(a[i] < b[i]){
                    count++; 
                }
            }
            return count > 2; 
        });
        // now need to check weather top element really is the one we requires
        bool found = true; 
        auto &x = v[res[0]];
        for(int i=0;i<n;i++){
            if(i == res[0]) continue; 
            if(!superior(x,v[i])){
                found = false;
                break; 
            }
        }
        if(found){
            cout<<res[0] + 1<<endl; 
        }
        else{
            cout<<-1<<endl; 
        }
    }
    return 0;
}