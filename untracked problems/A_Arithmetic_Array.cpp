// if sum < required for this then 1 element 
// else we need to increase n using 0 appended in array 
#include<bits/stdc++.h>
using namespace std; 
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int n; 
        cin>>n; 
        int sum = 0; 
        int num; 
        for(int i=0;i<n;i++){
            cin>>num; sum += num; 
        }
        if(sum == n){
            cout<<"0"<<endl; 
        }
        else if(sum <= n+1){
            cout<<"1"<<endl; 
        } 
        else{
            cout<<(sum - n )<<endl; 
        }
    }
}