// we need to consider from 2nd sequence of size 2 
// replace 2 characters with new one 
// then check weather we can get good results as compared to previous replacement 
// during this only some part is under consideration/checked /
// once previous string is larger that is going to be answer since that is most significant bit 
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
 

void solve(){
    string s; 
    cin>>s; 
    int n = s.length(); 
    // if someone getting replaced with 2 digits 
    // then taking last such replacement as our 1 step replacement will be optimal 
    // since a+b > ab is never possible is a+b is giving 2 digit number 
    // if single digit replacement are being made at every place then we need to consider 3 number sequence 
    int id2 = -1; 
    for(int i=0;i+1<n;i++){
        int n1 = s[i] - '0'; 
        int n2 = s[i+1] - '0'; 
        if((n1 + n2) >= 10){
            id2 = i; 
        }
    }
    if(id2 == -1){
        int id1 = -1; 
        for(int i=1;i+1<n;i++){
            int n1 = s[i-1] - '0'; 
            int n2 = s[i] - '0'; 
            int n3 = s[i+1] - '0'; 
            int sum = n1 + n2; 
            // if(sum == 10) sum = 1; 
            int prevNum = sum*10 + n3; 
            sum = n2 + n3; 
            // if(sum == 10) sum = 1; 
            int newNum = n1*10 + sum; 
            if(newNum < prevNum){
                id1 = i-1; 
                break; 
            }
        }
        if(id1 == -1){
            id1 = n-2; 
        }
        for(int i=0;i<n;i++){
            if(i == id1){
                cout<<(s[i] + s[i+1] - 2*'0'); 
                i++; 
            }
            else{
                cout<<s[i]; 
            }
        }
        cout<<endl; 
    }
    else{
        int n1 = s[id2] - '0'; 
        int n2 = s[id2+1] - '0'; 
        int sum = n1 + n2; 
        s[id2] = sum/10 + '0'; 
        s[id2+1] = sum%10 + '0'; 
        cout<<s<<endl; 
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