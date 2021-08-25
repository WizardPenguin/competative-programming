// convert each strin ginto frequency vector
// then sort for each character according to difference of it's freqnency and whole length 
#include <bits/stdc++.h> 
#include <complex>
#include <cmath>
// ***** take care of 2*consideration - size
// ***** also we need to add 2 more cases for better runtime 
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
#define size 26
int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n;  cin>>n; 
        string s; 
        vector<vector<int> > v(n,vector<int>(27,0));
        for(int i=0;i<n;i++){
            cin>>s; 
            for(auto x: s){
                v[i][x - 'a']++; 
            }
            v[i][size] = s.length(); 
        }
        // we need to sort according to differency using priority queue who sorts based on a global variable 
        int consideration = 0; 
        auto comprator = [&consideration,&v](const int &a,const int &b){
            auto &v1 = v[a];
            auto &v2 = v[b];
            if((v1[consideration] == 0) and (v2[consideration] == 0)){
                return v1[size] > v2[size]; 
            }
            if((2*v1[consideration] - v1[size]) < (2*v2[consideration] - v2[size])){
                return true; 
            }
            else if((2*v1[consideration] - v1[size]) == (2*v2[consideration] - v2[size])){
                // return one with more c's 
                return v1[consideration] < v2[consideration];
            }
            return false; 
        };
        int ans = INT_MIN;
        for(int i=0;i<26;i++){
            consideration = i; 
            priority_queue<int,vector<int>,decltype(comprator)> pq(comprator);
            for(int x=0;x<n;x++){
                pq.push(x);
            }
            // remove element than can be removed
            int taken = 0; 
            int len = 0; 
            int cnt = 0; 
            while(!pq.empty()){
                int ele = pq.top(); 
                pq.pop(); 
                len += v[ele][size];
                cnt += v[ele][consideration];
                // cout<<len<<" "<<cnt<<endl; 
                if(cnt > (len - cnt)){
                    taken++; 
                }
                else break; 
            }
            // dbg(taken);
            ans = max(taken,ans);
        }
        cout<<ans<<endl; 
    }
    return 0;
}