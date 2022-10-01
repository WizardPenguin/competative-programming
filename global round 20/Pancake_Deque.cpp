#include<bits/stdc++.h>
using namespace std; 
int main(){
    int test; 
    cin>>test; 
    for(int i=1;i<=test;i+=1){
        cout<<"Case #"<<i<<": "; 
        int n ;
        cin>>n; 
        vector<int> v(n); 
        for(int i=0;i<n;i+=1) cin>>v[i]; 
        int previous = -1; 
        int start = 0; 
        int end = n-1; 
        int ans = 0; 
        while(start <= end){
            if(v[start] < v[end]){
                if(v[start] >= previous){
                    previous = v[start]; 
                    ans += 1; 
                }
                start += 1; 
            }
            else{
                if(v[end] >= previous){
                    previous = v[end]; 
                    ans += 1; 
                }
                end -= 1; 
            }
        }
        cout<<ans<<endl; 
    }
}