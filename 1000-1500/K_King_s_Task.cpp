// observed for even length only 4 permutations were possible 
// and for odd n we had n permutations after then it converges back 
// these permutations were found by repeating consecutive step 1-2-1-2 etc
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
void findPern(vector<vector<int> > &res,vector<int>&temp){
    // works in O(N^2)
    // finds all permutations in case of n is odd
    int step = 1; 
    int move = 1; 
    int hlf = res[0].size()/2; 
    int pern ;
    if((hlf&1) == 1){
        pern = 2*hlf; 
    }
    else{
        pern = 4; 
    }
    while(step < pern){
        temp = res[step-1]; 
        if(move){
            for(int i=0;i<2*hlf;i+=2){
                swap(temp[i],temp[i+1]); 
            }
        }
        else{
            for(int i=0;i<hlf;i++){
                swap(temp[i],temp[hlf+i]); 
            }
        }
        res.push_back(temp); 
        move = 1-move; 
        step++; 
    }
    return; 
}
int main()
{
    fast_cin();
    int n; 
    cin>>n; 
    n*=2;
    vector<vector<int> > v(1,vector<int>(n));
    vector<int> toFind(n); 
    for(int i=0;i<n;i++) cin>>toFind[i],v[0][i] = i+1; 
    vector<int> temp;
    findPern(v,temp); 
    int foundId = -1 ; 
    for(int i=0;i<v.size();i++){
        if(v[i] == toFind){
            foundId = i; 
            break; 
        }
    }
    if((n/2)&1) // odd 
    cout<<min(foundId,n-foundId)<<endl; 
    else
    cout<<min(foundId,4-foundId)<<endl; 
    return 0;
}