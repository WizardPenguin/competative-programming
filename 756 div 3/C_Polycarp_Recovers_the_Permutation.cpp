#include<bits/stdc++.h>
using namespace std; 
#define ll long long 
#define v32 vector<int> 
#define vv32 vector<vector<int> > 
#define pii pair<int,int> 
v32 makeOp(v32 &v,bool l){
    int i=0; 
    int j = v.size()-1; 
    list<int> res; 
    while(i < j){
        if(v[i]  < v[j]){
            res.push_front(v[i]); 
            i++; 
        }
        else{
            res.push_back(v[j]); 
            j--; 
        }
    }
    if(i == j){
        if( l){
            res.push_back(v[j]); 
        }
        else{
            res.push_front(v[j]); 
        }
    }
    v32 ret; 
    for(auto it = res.begin(); it != res.end();it++){
        ret.push_back(*it); 
    }
    return ret;  
}
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int n; 
        cin>>n; 
        v32 v(n); 
        for(int i=0;i<n;i++) cin>>v[i]; 
        v32 r1 = makeOp(v,false); 
        v32 r2 = makeOp(v,true); 
        // for(auto i: r1) cout<<i<<" "; 
        // cout<<endl; 
        // for(auto i: r2) cout<<i<<" "; 
        // cout<<endl; 
        v32 r11 = makeOp(r1,false); 
        v32 r12 = makeOp(r1,true); 
        if(r11 == v or r12 == v){
            for(auto &i: r1){
                cout<<i<<" "; 
            }
            cout<<endl; 
        }
        else{
            v32 r21 = makeOp(r2,false); 
            v32 r22 = makeOp(r2,true); 
            if(r21 == v or r22 == v){
                for(auto &i: r2){
                    cout<<i<<" "; 
                }
                cout<<endl; 
            }
            else{
                cout<<-1<<endl; 
            }
        }
    }
}