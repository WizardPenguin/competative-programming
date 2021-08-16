// start with any color 
// after then when known found choose opposite to next place 
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
void reverse(char &s){
    if(s == 'B') s = 'R';
    else s = 'B'; 
    return; 
}
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n; 
        cin>>n; 
        string s; 
        cin>>s; 
        string temp = s; 
        char start = 'B'; 
        for(int i=0;i<n;i++){
            if(s[i] == '?'){
                s[i] = start; 
                reverse(start); 
            }
            else{
                start = s[i]; 
                reverse(start); 
            }
        }
        int value = 0; 
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]) value++; 
        }
        string prev = s; 
        s = temp; 
        start = 'R'; 
        for(int i=0;i<n;i++){
            if(s[i] == '?'){
                s[i] = start; 
                reverse(start); 
            }
            else{
                start = s[i]; 
                reverse(start); 
            }
        }
        int val2 = 0; 
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]) val2++; 
        }
        if(value <= val2){
            cout<<prev<<endl; 
        }
        else{
            cout<<s<<endl; 
        }
    }
    return 0;
}