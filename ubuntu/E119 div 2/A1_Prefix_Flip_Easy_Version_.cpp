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
void flip(string &a,int i,int j){
    for(int x =i; x<=j;x++){
        if(a[x] == '1'){
            a[x] = '0'; 
        }
        else{
            a[x] = '1'; 
        }
    }
}
void reverse(string &a,int i,int j){
    while(i<j){
        swap(a[i],a[j]); 
        i++,j--; 
    }
    return; 
}
bool check(string &a,string &b,vi& res){
    for(auto &i: res){
        flip(a,0,i-1); 
        reverse(a,0,i-1);
    }
    cout<<a<<endl; 
    return a == b; 
}
// we are requird to flip jth bit , in real ith 1st bit of array 
// if flip is not required i.e. jth bit = reverse of b[bi] bit then skip it 
// after then we are required to make flip parameter showing each bit's status either flipped or not 
// next operation is going to be at prefix till ith bit which is bi + 1th bit in reality 
// this will mark all bits flip so change flip parameter accordingly 
void solve(){
    int n; 
    cin>>n; 
    string a,b; 
    cin>>a>>b; 
    int bi = n-1; 
    int ai = n-1; 
    int flip = 0; 
    int aj = 0; 
    // flip changes flip parameter 
    // reverse changes ith and jth pointer since their exact location is bi and 0 respectively 
    vi res; 
    for(int i=0;i<n;i++){
        // we have to operate n times 
        if(!flip and a[ai] == b[bi] or (flip and a[ai] != b[bi])){
            bi--; 
            if(flip) ai++; 
            else ai--; 
        }
        else{
            // base case when single element is there 
            if(ai == aj){
                if(flip){
                    if(a[ai] == b[bi]){
                        res.push_back(1); 
                    }
                }
                else{
                    if(a[ai] != b[bi]){
                        res.push_back(1); 
                    }
                }
            }
            else if(flip){
                if(a[aj] == b[bi]){
                    // only reverse 
                    res.push_back(bi+1); 
                }
                else{
                    // flip and reverse
                    res.push_back(1);
                    res.push_back(bi+1); 
                }
                // fliped so ai has been swaped with aj so it needs increase 
                aj--;  
            }
            else{
                if(a[aj] == b[bi]){
                    // flip and reverse
                    res.push_back(1); 
                    res.push_back(bi+1); 
                }   
                else{
                    // direct reverse  
                    res.push_back(bi+1); 
                }
                // both ai and aj are at their respective positions 
                aj++;  
            }
            bi--; 
            swap(ai,aj); 
            flip = 1-flip; 
            // flip parameter also tells weather ai has to be increased or decreased after application of operation 
        }
    }
    // dbg(check(a,b,res))<<endl; 
    cout<<res.size()<<" ";  
    for(auto &i: res) cout<<i<<" "; 
    cout<<endl; 
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