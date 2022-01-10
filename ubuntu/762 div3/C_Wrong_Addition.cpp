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
bool found = true; 
string find(string &a,string &b,int i,int j){
    if(i<0){
        if(j>=0){
            // dbg(b.substr(0,j+1));
            auto rem = b.substr(0,j+1); 
            reverse(all(rem)); 
            return rem; 
        }
        else return "";
    }
    if(j < 0){ // means all characters for solution are triversed 
        found = false; 
        return ""; 
    }
    if(a[i] > b[j]){
        // means we are forced to take 2 characters 
        if(j >= 1){
            int r = (b[j-1] - '0')*10 + b[j] - '0'; 
            int l = a[i] - '0'; 
            if((r > (9 + l)) or r < l){
                found = false; 
                return ""; 
            }
            int rem = r - l; 
            if(rem < 0){
                found = false; 
                return ""; 
            }
            return to_string(rem) + find(a,b,i-1,j-2); 
        }
        else{
            found = false; 
            return ""; 
        }
    }
    else{
        int rem = b[j] - a[i]; 
        return to_string(rem) + find(a,b,i-1,j-1); 
    }
}
void solve(){
    string a,b; 
    cin>>a>>b; 
    found = true; 
    if(a.length() > b.length()){
        cout<<-1<<endl; 
        return; 
    }
    string res = find(a,b,a.length()-1,b.length()-1); 
    if(found){
        reverse(all(res)); 
        int i=0; 
        while(i<res.size()){
            if(res[i] == '0') i++; 
            else break; 
        }
        if(i == res.size()){
            cout<<"0"; 
            return;
        }
        for(i;i<res.size();i++){
            cout<<res[i]; 
        }
        cout<<endl; 
    }
    else{
        cout<<-1<<endl; 
    }
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