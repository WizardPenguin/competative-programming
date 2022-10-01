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
/// ### using 1 based indexing 
int different = 0; 
int searchQuery(vector<int> &v,int id){
    // now finding exact index to which it matches in previous area's 
    vector<bool> used(100,false); 
    vector<pair<int,int> > distinct; 
    int diff = 0,res=0; 
    for(int i=id-1;i>0;i-=1){
        if(used[v[i]] == false){
            // if it's not already been used 
            diff += 1; 
            used[v[i]] = true; 
            distinct.push_back({i,diff}); 
        }
    }
    reverse(all(distinct)); 
    // now we have all distinct characters and their indices use binary search on them 
    // indices which doesn't have matching characters will give diff + 1 as result
    // while index which has matching character in them will give diff as result since it's already considered
    int left = 0,right = distinct.size()-1; 
    while(left < right){
        int mid = (left + right+1) >> 1; 
        // cerr<<mid<<endl; 
        // cerr<<distinct[mid].first<<" h "<<endl; 
        cout<<"? 2 "<<distinct[mid].first<<" "<<id<<endl; 
        cin>>res; 
        if(res == distinct[mid].second){
            // try to increase a bit
            left = mid; 
        }
        else{
            right = mid-1; 
        }
    }
    // cerr<<left<<endl; 
    return v[distinct[left].first]; 
}
void solve(){
    int n; 
    cin>>n; 
    if(n == 1){
        cout<<"? 1 "<<1<<endl; 
        char ch;
        cin>>ch; 
        cout<<"! "<<ch<<endl; 
        return; 
    }
    vector<int> v(n+1,0); 
    cout<<"? 2 "<<1<<" "<<2<<endl;
    int res; 
    cin>>res; 
    if(res == 2){
        different = 2; 
        v[1] = 1; 
        v[2] = 2; 
    } 
    else{
        // res must be 1 
        different =1; 
        v[1] = v[2] = 1; 
    }
    // now ask queries for remaining things 
    for(int i=3;i<=n;i+=1){
        cout<<"? 2 "<<1<<" "<<i<<endl; 
        cin>>res; 
        if(res == different+1){
            different += 1; 
            v[i] = different;  
        }
        else{
            if(res == 1){
                v[i] = v[i-1]; // these are same character as previous 
            }
            else v[i] = searchQuery(v,i); 
        }
    }
    map<int,char> mp; 
    // now finding mapping using query's of type 1 
    vector<int> visited(100,false); 
    for(int i=1;i<=n;i+=1){
        if(visited[v[i]]) continue; 
        visited[v[i]] = true; 
        cout<<"? 1 "<<i<<endl; // search character at this index 
        cin>>mp[v[i]]; 
    }
    // return string by mapping 
    cout<<"! "; 
    for(int i=1;i<=n;i+=1){
        cout<<mp[v[i]]; 
    }
    cout<<endl; 
}
int main(){
    vi v; 
    
    solve(); 
    return 0;
}