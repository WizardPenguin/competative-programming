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
#define dbg(x) cerr<<#x<<" = "<<x<<ln
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
struct Data{
    set<int> st,search; 
    int offset,modulo,val; 
    Data(){}
    Data(int n){
        val = n; 
        auto tp = n%10; 
        if(tp&1){
            offset = tp; 
        }
        tp = (2*tp)%10;
        search.insert(0);
        while(st.find(tp%10) == st.end()){
            search.insert(*prev(search.end()) + tp); 
            st.insert(tp%10); 
            tp += tp%10; 
        }
        debug(st,search); 
    }
    bool find(int n){ // check weather we can reach to number n 
        int diff = n - val; 
        if(diff == 0) return true; 
        if(diff < offset) return false; 
        diff -= offset; 
        return search.find(diff) != search.end(); 
    }
}; 
void solve(){
    int n;  cin>>n; 
    vi v(n); 
    bool found = false;  
    for(int i=0;i<n;i+=1) cin>>v[i], found = (found or (v[i]%10 == 5) or (v[i]%10 == 0)); 
    // return;
    dbg(found); 
    // we have cases when we have atlest 1 with modulo 5 or 0, check them separately 
    int maxi = *max_element(all(v)); 
    if(found){
        found = true; 
        if(maxi%10 == 5){
            for(auto &i: v){
                if(i != maxi){ found = false;break;}
            }
            if(found) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;  
        }
        else{
            for(auto &i: v){
                if(i != maxi-5 and i != maxi){
                    found = false; break; 
                }
            }
            if(found) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;  
        }
        return; 
    }
    dbg("not found"); 
    vector<Data> d; 
    for(int i=0;i<n;i+=1){
        d.push_back(Data(n)); 
    }
    auto check = [&](int n){
        for(int i=0;i<n;i+=1){
            if(not d[i].find(n)) return false; 
        }
        return true; 
    };
    int id = max_element(all(v)) - v.begin(); 
    if(check(maxi) or check(maxi + d[id].offset)){
        cout<<"Yes"<<endl; 
        return; 
    }
    maxi += d[id].offset;
    for(auto &elm: d[id].search){
        maxi += elm; 
        if(check(maxi)){
            cout<<"Yes"<<endl; 
            return; 
        }
    }
    cout<<"No"<<endl; 
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