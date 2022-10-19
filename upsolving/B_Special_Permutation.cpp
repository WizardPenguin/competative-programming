#include<bits/stdc++.h>
using namespace std; 
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int n,a,b; 
        cin>>n>>a>>b; 
        vector<int> left; 
        vector<int> right; 
        if(a < b){
            left.push_back(a); 
            for(int i=b+1;i<=n;i++){
                left.push_back(i);
            }
            right.push_back(b); 
            for(int j=a-1;j>0;j--){
                right.push_back(j); 
            }
            if(left.size() > n/2 or right.size() > n/2){
                cout<<-1<<endl;
                goto end; 
            }
            else{
                int i = a + 1; 
                while(left.size() < n/2){
                    left.push_back(i); 
                    i++; 
                }
                while(right.size() < n/2){
                    right.push_back(i); 
                    i++; 
                }
            }
        }
        else{
            int canl = n - a + 1; 
            int canr = b; 
            if(canl == n/2 and canr == n/2){
                // cout<<"found"<<endl; 
                for(int i=1;i<=b;i++){
                    right.push_back(i); 
                }
                for(int i=a;i<=n;i++){
                    left.push_back(i); 
                }
            }
            else{
                cout<<-1<<endl; 
                goto end; 
            }
        }
        for(auto &i: left) cout<<i<<" "; 
        for(auto &j: right) cout<<j<<" "; 
        cout<<endl; 
        end:;
    }
}