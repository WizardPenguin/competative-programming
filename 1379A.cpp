// try using burteforce 
// each if 0 occurence of string found in given string then we can replace each ? with a,b,c 
// check weather they have created > 1 occurences of given string 
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
string compare = "abacaba"; 
#define N 7
bool match(string &s,int id){
    for(int i=0;i<N;i+=1){
        if(s[i+id] != compare[i]) return false; 
    }
    return true; 
}
bool similar(string &s,int id){
    for(int i=0;i<N;i+=1){
        if(s[i+id] != '?' and s[i+id] != compare[i]) return false; 
    }
    return true; 
}
int countOccurences(string &s){
    int count = 0; 
    for(int i=0;i<s.length()-N+1;i+=1){
        count += match(s,i); 
    }
    return count; 
}
void solve(){
    int n; 
    cin>>n; 
    string s; 
    cin>>s; 
    int baseOccurences = countOccurences(s); 
    if(baseOccurences > 1){
        cout<<"No"<<endl; 
    }
    else if(baseOccurences == 1){
        // replace all ? with desired characters
        cout<<"Yes"<<endl; 
        for(int i=0;i<n;i+=1){
            if(s[i] == '?') s[i] = 'd'; 
        }
        cout<<s<<endl; 
    }
    else{
        // if similar then replace and check weather replacement was succesful or not 
        for(int i=0;i<n-N+1;i+=1){
            if(similar(s,i)){
                auto tp = s; 
                for(int j=0;j<N;j+=1){
                    tp[i+j] = compare[j]; 
                }
                if(countOccurences(tp) == 1){
                    cout<<"Yes"<<endl; 
                    for(int i=0;i<n;i+=1){
                        if(tp[i] == '?') tp[i] = 'd'; 
                    }
                    cout<<tp<<endl; 
                     return; 
                }
            }
        }
        cout<<"No"<<endl; 
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