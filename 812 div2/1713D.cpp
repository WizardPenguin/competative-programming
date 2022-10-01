#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<vector<pll> > vvpll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<vector<bool> > vvb;
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
void solve(){
    int n; 
    cin>>n; 
    vector<int> v; 
    for(int i=1;i<=(1<<n);i+=1){
        v.push_back(i); 
    }
    while(v.size() >= 4){
        vector<int> tp; 
        for(int i=0;i + 3<v.size();i+=4){
            int a = v[i],b = v[i+1],c = v[i+2],d = v[i+3]; 
            cout<<"? "<<b<<" "<<c<<endl; 
            int val; 
            cin>>val; 
            if(val == 0){
                // definately both are looser at this level 
                cout<<"? "<<a<<" "<<d<<endl; 
                cin>>val; 
                if(val == 1) tp.push_back(a);
                else tp.push_back(d); 
            }
            else if(val == 1){
                // means b has won this match so a, c are loser just compare with d
                cout<<"? "<<b<<" "<<d<<endl;
                cin>>val;
                if(val == 1)tp.push_back(b); 
                else tp.push_back(d); 
            }
            else{
                // means c has won this match so b,d are looser 
                cout<<"? "<<c<<" "<<a<<endl; 
                cin>>val;
                if(val == 1) tp.push_back(c); 
                else tp.push_back(a); 
            }
        }
        swap(tp,v); 
    }
    int ans = v[0]; 
    for(int i=1;i<v.size();i+=1){
        cout<<"? "<<ans<<" "<<v[i]<<endl; 
        int val; 
        cin>>val; 
        if(val == -1){
            cout<<"NO"<<endl; 
            return;
        }
        if(val == 2){
            ans = v[i]; 
        }
    }
    cout<<"! "<<ans<<endl; 
}
int main(){
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        solve();
    }
    return 0;
}