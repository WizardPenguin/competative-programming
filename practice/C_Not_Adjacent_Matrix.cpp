// completely pattern based algo
// find pattern such that adjacent elements are not adjacent then implement it 
#include<bits/stdc++.h>
using namespace std; 
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int n; 
        cin>>n;
        if(n == 1){
            cout<<1<<endl; continue; 
        }
        if(n == 2){
            cout<<-1<<endl; continue; 
        } 
        vector<int> v; 
        for(int i=1;i<=n*n;i+=2){
            v.push_back(i);
        }
        for(int i=2;i<=n*n;i+=2){
            v.push_back(i);
        }
        int x =0; 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<v[x]<<" ";
                x++; 
            }
            cout<<endl; 
        }
    }
    return 0; 
}
