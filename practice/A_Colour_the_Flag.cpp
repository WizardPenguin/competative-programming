// 50x50 grid and 100 test cases; 
// fill it either using first cell as white or red
// if none satisfies condition then return false; 
#include<bits/stdc++.h>
using namespace std; 
bool fill(vector<vector<int> > &v,int c){
    // 0,0 is colored with color c;
    // when r = even then at even pos color c
    vector<vector<int> > grid = v; 
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if((i&1) == (j&1)){
                if(grid[i][j] == -1){
                    grid[i][j] = c; 
                }
                else if(grid[i][j] != c) return false; 
            }
            else{
                if(grid[i][j] == -1){
                    grid[i][j] = 1-c; 
                }
                else if(grid[i][j] != 1-c) return false; 
            }
        }
    }
    v = grid; 
    return true; 
}
void print(vector<vector<int> > &v){
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[0].size();j++){
            if(v[i][j]) cout<<"R"; 
            else cout<<"W";
        }
        cout<<endl; 
    }
    return; 
}
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int m,n; 
        cin>>n>>m; 
        char c; 
        vector<vector<int> > v(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){ 
            for(int j=0;j<m;j++){
                cin>>c;
                if(c == 'R'){
                    v[i][j] = 1; 
                }
                else if(c == 'W'){
                    v[i][j] = 0; 
                }
            }
        }
        if(fill(v,1)){
            cout<<"YES"<<endl; 
            print(v); 
        }
        else if(fill(v,0)){
            cout<<"YES"<<endl; 
            print(v); 
        }
        else{
            cout<<"NO"<<endl; 
        }
    }
}
