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
vector<array<int,3> > info = {
    {3,1,2},{1,2,3},{2,3,1}
}; 
void print(vector<int> &v){
    for(int i=1;i<v.size();i+=1){
        cout<<v[i-1]<<" "<<v[i]<<endl; 
    }
}
void printRemaining(int toTake,int n){
    while(toTake <= n){
        cout<<1<<" "<<toTake++<<endl; 
    }
}
void solve(){
    array<int,3> data; 
    int n; cin>>n; 
    for(auto &elm: data) cin>>elm; 
    int maxi = max({data[0],data[1],data[2]}); 
    for(int i=0;i<3;i+=1){
        if(data[i] == maxi){
            // this is going to be on base now we want to divide these for left and right elements
            int left = data[(i+2)%3]; 
            int right = data[(i+1)%3]; 
            if(left + right == maxi){
                // then we shurely have 1 way of solution check weather it faviours us or not
                cout<<"YES"<<endl; 
                vi middle; middle.push_back(info[i][1]); 
                int toTake = 4; 
                for(int i=0;i<left-1;i+=1) middle.push_back(toTake++);  middle.push_back(info[i][0]); 
                for(int i=left;i<maxi-1;i+=1) middle.push_back(toTake++); middle.push_back(info[i][2]);
                // now we need extra edges to be handled
                print(middle); 
                printRemaining(toTake,n);  
                return;
            }
            for(int j=1;j<left;j+=1){
                int leftRemaining = left - j; 
                if((leftRemaining + (maxi-j)) == right and (leftRemaining + maxi +1) <= n ){
                    cout<<"YES"<<endl;
                    vector<int> middle,t;  middle.push_back(info[i][1]); 
                    int toTake = 4; 
                    for(int x=0;x<maxi-1;x+=1) middle.push_back(toTake++); middle.push_back(info[i][2]); 
                    t.push_back(middle[j]); 
                    for(int x=0; x<leftRemaining-1;x+=1) t.push_back(toTake++);  t.push_back(info[i][0]);
                    // debug(t); 
                    print(middle); print(t); printRemaining(toTake,n); 
                    return; 
                }
            }
        }
    }
    cout<<"NO"<<endl; 
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