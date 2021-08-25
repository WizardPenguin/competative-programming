#include<bits/stdc++.h>
using namespace std; 
int main(){
    int test; 
    cin>>test; 
    while(test--){
        int n; 
        cin>>n; 
        int temp = n; 
        int nDigit = 0; 
        int lastDigit = 0;
        while(n){
            lastDigit = n%10;
            n = n/10;
            nDigit ++;
        }
        int bound = 0; 
        for(int i=0;i<nDigit;i++){
            bound = bound * 10 + lastDigit;
        }
        nDigit --;
        // we don't need to consdier 0
        if(temp >= bound){
            cout<<(lastDigit + nDigit*9)<<endl; 
        }
        else{
            cout<<(lastDigit - 1 + nDigit*9)<<endl; 
        }
    }
    return 0; 
}