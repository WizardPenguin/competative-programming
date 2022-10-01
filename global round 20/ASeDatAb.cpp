#include<bits/stdc++.h>
using namespace std; 
int main(){
    int test; 
    cin>>test; 
    for(int i=1;i<=test;i+=1){
        int val = 1;   
        while(val > 0){
            cout<<bitset<8>((1<<4)-1)<<endl; 
            cin>>val; 
        }
        if(val == -1){
            return 0; 
        }
    }
    return 0; 
}