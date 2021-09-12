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
        int n; cin>>n; 
        string s; 
        cin>>s; 
        vector<int> twos; 
        // make all draw
        vector< vector<char> > mat(n,vector<char>(n,'=')); 
        for(int i=0;i<n;i++) mat[i][i] = 'X'; 
        for(int i=0;i<n;i++){
            if(s[i] == '2'){
                twos.push_back(i); 
            }
        }
        // for(auto i: twos) cout<<i<<" "; 
        // cout<<endl;
        if(twos.size() == 0){
            cout<<"YES"<<endl; 
            for(auto &i: mat){
                for(auto &j: i){
                    cout<<j;
                }
                cout<<endl; 
            }
        }
        else if(twos.size() == 1 or twos.size() == 2){
            cout<<"NO"<<endl; 
        }
        else{
            cout<<"YES"<<endl; 
            int sz = twos.size(); 
            for(int i=0;i<sz-1;i++){
                // for each person winn against it's forward person
                // cout<<twos[i]<<" "<<twos[i+1]<<endl;  
                mat[twos[i]][twos[i+1]] = '+'; 
                mat[twos[i+1]][twos[i]] = '-'; 
            }
            // mast one wins agaist first one 
            int last = twos[sz-1]; 
            mat[last][twos[0]] = '+';
            mat[twos[0]][last] = '-'; 
            for(auto &i: mat){
                for(auto &j: i){
                    cout<<j;
                }
                cout<<endl; 
            }
        }
    }
    return 0;
}