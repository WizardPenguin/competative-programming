#include<bits/stdc++.h>
using namespace std; 
#define ll long long 
#define v32 vector<int> 
#define vv32 vector<vector<int> > 
#define pii pair<int,int> 
int main(){
    int test; 
    cin>>test; 
    while(test--){
        string s; 
        cin>>s; 
        // reverse(s.begin(),s.end()); 
        v32 v; 
        for(auto &i: s) v.push_back(i - '0'); 
        // for(auto &i: v) cout<<i<<" "; 
        int n = v.size(); 
        if(v[n-1]%2 == 0){
            cout<<0<<endl; 
        }
        else if(v[0] % 2 == 0){
            cout<<1<<endl; 
        }
        else{
            bool found = false; 
            for(int i=0;i<n;i++){
                if(v[i]%2 == 0){
                    found = true; 
                }
            }
            if(found){
                cout<<2<<endl; 
            }
            else{
                cout<<-1<<endl; 
            }
        }
    }
}