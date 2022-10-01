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
#define N 300
bool checkComplete(string &s){
    char ch = s[0]; 
    for(auto &c: s){
        if(ch != c) return false; 
    }
    return true; 
}
bool found = true; 
bool checkAll(vi &s,vi &e,vi &m,string &str,int id){
    auto start = str[0]; 
    auto end = str.back(); 
    int i=0; 
    int j = str.length()-1; 
    if(s[start] != -1 or m[start] != -1){
        return false; 
    }
    if(e[end] != -1 or m[end] != -1){
        return false; 
    }
    // now check 
    while(str[i] == start)i+=1; 
    while(str[j] == end) j-=1; 
    // now insert middle values 
    for(int x=i;x<=j;x+=1){
        if(s[str[i]] != -1 or e[str[i]] != -1 or m[str[i]] != -1){
            return false; 
        }
        m[str[i]] = id; 
    }
    s[start] = id; 
    e[end] = id; 
    return true; 
}
int find(vi parent,vi rank,int i){
    if(parent[i] == -1) return i; 
    return parent[i] = find(parent,rank,parent[i]); 
}
bool join(vi parent,vi rank,int x,int y){
    cerr<<x<<" "<<y<<endl; 
    int px = find(parent,rank,x); 
    int py = find(parent,rank,y); 
    if(px == py) return false; 
    if(rank[px] > rank[py]){
        rank[px] += rank[py]; 
        parent[py] = px; 
    }
    else{
        rank[py] += rank[px]; 
        parent[px] = py; 
    }
    return true; 
}
int findP(vi cmp,vi start,vi end){
    // if no end means it's parent 
    for(auto &id: cmp){
        if(end[id] == -1) return id; 
    }
    cerr<<"invalid parent found"<<endl; 
    return -1; 
}
string find(vi cmp,vs v,vi start,vi end,vvi complete){
    int startId = findP(cmp,start,end); 
    string res; 
    // now joining them , we know there is no cycle so we can join without any error in iterative manner
    while(startId >= 0){
        res += v[end[startId]]; 
        for(auto &id: complete[startId]){
            res += v[id]; 
        }
        res += v[start[startId]]; 
        startId = res.back(); 
    }
    return res; 
}
void solve(){
    int n; 
    cin>>n; 
    vs v(n); 
    for(int i=0;i<n;i+=1) cin>>v[i]; 
    // now find start and ends // if already started or ended then we can't find solution 
    // find mid's if they have any start or end then we are done here 
    vi start(N,-1),end(N,-1),mid(N,-1); 
    vvi complete(N); 
    // now compute
    for(int i=0;i<n;i+=1){
        string &s = v[i]; 
        if(checkComplete(s)){
            complete[s.back()].push_back(i); 
            continue; 
        }
        // now find start and end indices 
        int st = s[0]; 
        int ed = s.back(); 
        if(not checkAll(start,end,mid,s,i)){
            cout<<"IMPOSSIBLE"<<endl; 
            return; 
        }
    }
    cerr<<"all logs generated"<<endl; 
    // now need to make final solution by finding connected components 
    // joining each start and ends needed here 
    vector<int> parent(n,-1); 
    vector<int> rank(n,1); 
    for(int i=0;i<N;i+=1){
        // join start with it's end 
        // join end with it's start 
        if(start[i] != -1 and end[i] != -1){
            cerr<<i<<" calling for logs"<<endl; 
            int sid = start[v[start[i]].back()]; 
            int eid = end[v[end[i]][0]]; 
            if(not join(parent,rank,sid,eid)){
                cout<<"IMPOSSIBLE"<<endl; 
            }
        }
    }
    cerr<<"all components formed "<<endl; 
    // find each componenet and return string formed by them 
    vvi components(N); 
    for(int i=0;i<N;i+=1){
        if(end[i] != -1){
            // means they have valid things 
            int p = find(parent,rank,i); 
            components[p].push_back(i); 
        }
    }
    // find result using these components 
    string res; 
    for(int i=0;i<N;i+=1){
        if(components.size()){
            res += find(components[i],v,start,end,complete); 
        }
    }
    cout<<res<<endl; 
}

int main(){
    fast_cin();
    ll test;
    cin >> test;
    for(int i=1;i<=test;i+=1){
    cout<<"Case #"<<i<<": "; 
        solve();
    }
    return 0;
}