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
string s; 
int fnxn(int left,int right){ // we are passing indices of string that need to be taken under consideration
    if(left >= right) return 0; 
    int i=right; 
    int done =0;
    int l;   
    while(left <= i){
        if(s[i] == ')'){ // shurely we are going to balance these things are at end we'll get its opening bracket
            l = 0; 
            right = i; 
            do{ 
                if(s[i] == ')') l++; 
                else if(s[i] == '(') l--; 
                i--; 
            }while(l != 0);
            // call function removing last bracket
            // cout<<(i+2)<<" "<<right-1<<endl; 
            done = fnxn(i+2,right-1); 
        }
        else if(s[i] == '>'){
            // means we need a functional call  
            i-=2; 
            l=0; 
            right = i;  
            do{
                if(s[i] == ')') l++; 
                else if(s[i] == '(') l--; 
                i--; 
            }while(l != 0);
            // cout<<(i+2)<<" "<<right-1<<endl; 
            done = max(fnxn(i+2,right-1) + 1,done); 
        }
        // dbg(done);
    }
    return done; 
}
int main()
{
    fast_cin();
    cin>>s; 
    cout<<fnxn(0,s.length()-1);
    return 0;
}