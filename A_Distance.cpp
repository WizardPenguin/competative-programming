#include<bits/stdc++.h>
using namespace std; 
#define pii pair<int,int>
#define N 1000
int dist(pii x,pii y){
    return abs(x.first - y.first) + abs(x.second - y.second); 
}
int main(){
    int test; 
    cin>>test; 
    while(test--){
        pii a,b; 
        a = {0,0}; 
        cin>>b.first>>b.second;
        int d = dist(a,b); 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if((2*dist(a,{i,j}) == d )and (2*dist(b,{i,j}) == d)){
                    cout<<i<<" "<<j<<endl; 
                    goto end; 
                }
            }
        } 
        cout<<-1<<" "<<-1<<endl; 
        end:;
    }
}