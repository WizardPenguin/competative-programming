#include<bits/stdc++.h>
using namespace std; 
#define ll long long 
#define v32 vector<int> 
#define vv32 vector<vector<int> > 
#define pii pair<int,int>
#define SS 100005 
int  N = 0;
int ptr = 1; 
v32 dist; 
int root; 
// starting of pren should be root node 
bool dfs(vector<bitset<SS> > & graph,v32 &pern,int node){
    // cout<<node<<" "; 
    int sz = graph[node].count(); 
    // int sz = 1; 
    while(graph[node][pern[ptr]]){ // if next node is it's parent then we can make dfs 
        // make triversal 
        if(!dfs(graph,pern,pern[ptr++])) return false; 
        sz--; 
    }
    if(sz == 1 or (node == root and sz == 0)){ // all nbr's triversed without any conflict
        dist[node] = N; 
        N+=SS;
        return true;
    }
    else{
        return false; 
    } 
}
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int n; 
        cin>>n; 
        ptr = 1; 
        dist = v32(n+1,-1); 
        v32 v(n+1); 
        N = 0; 
        vector<bitset<SS> > graph(n+1);
        for(int i=1;i<=n;i++){
            cin>>v[i]; 
            if(v[i] == i){
                root = i; 
            }
            else{
                graph[i][v[i]] = 1;  
                graph[v[i]][i] = 1; 
            }
        } 
        v32 pern(n); 
        for(int i=0;i<n;i++) cin>>pern[i]; 
        if(pern[0] != root){
            cout<<-1<<endl; 
        }
        else{
            if(dfs(graph,pern,root)){
                for(int i=1;i<=n;i++)cout<<dist[i]<<" "; 
                cout<<endl; 
            }
            else{
                cout<<-1<<endl; 
            }
        }
    }
}