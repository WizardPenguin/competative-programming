#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int test; 
    cin>>test; 
    while(test--){
        ll a,b,x; 
        cin>>a>>b>>x; 
        // always replace larger one with difference 
        bool found = false; 
        while((a >= x or b >= x) and a and b ){
            // check 
            if(a == x or b == x ){
                found = true; 
                break; 
            }
            // from larger one we can substract smaller one by some number of times 
            if(a > b){
                swap(a,b); 
            }
            // a is smaller 
            ll d = b - x; 
            if(d%a == 0){
                found = true; 
                break; 
            }
            else{
                b -= (b/a)*a; 
            }
        }
        if(found){
            cout<<"YES"<<endl; 
        }
        else{
            cout<<"NO"<<endl; 
        }
    }
}