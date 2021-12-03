// ai is & with a(i-d) using this we can form a loops that might include whole array 
// from these loops we can find how many steps are required to make a zero to reach this node
// if all elements in loop are 1 then these elements never be converted to 0 so output -1 
// otherwise output steps after which all become 0
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


int main()
{
    fast_cin();
    ll test;
    cin >> test;
    while(test--){
        int n,d; 
        cin>>n>>d; 
        vector<int> v(n); 
        for(int i=0;i<n;i++){
            cin>>v[i]; 
        }
        int res =0; 
        vector<bool>  visited(n,false); 
        for(int i=0;i<n;i++){
            if(visited[i]) continue; 
            int start = i;
            vector<int> tp; 
            do{
                tp.push_back(v[start]); 
                visited[start] = true; 
                start = (start + n - d)%n; 
            }while( start != i); 
            int s = 0; 
            reverse(all(tp));
            // for(auto &i: tp) cout<<i<<" "; 
            // cout<<endl;
            while(s < tp.size()){
                if(tp[s] == 0) break; 
                s++; 
            }
            if(s == tp.size()){
                cout<<-1<<endl; 
                goto end; 
            }
            int ans = 0; 
            for(int j=s;j<tp.size();j++){
                if(tp[j]){
                    tp[j] = tp[j-1] + 1; 
                    ans = max(ans,tp[j]); 
                }
                // otherwise steps to make it 0 will remain 0
            }
            if(tp[0]){
                tp[0] = tp[tp.size()-1] + 1; 
            }
            ans = max(ans,tp[0]); 
            for(int j=1;j<s;j++){
                if(tp[j]){
                    tp[j] = tp[j-1] + 1; 
                    ans = max(ans,tp[j]); 
                }
            }
            res = max(res,ans); 
        }
        cout<<res<<endl; 
        end:; 
    }
    return 0;
}