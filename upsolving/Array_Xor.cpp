#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {
	int test; 
	cin>>test; 
	while(test--){
		int n; 
		cin>>n; 
		vector<int> v(n); 
		for(int i=0;i<n;i+=1) cin>>v[i]; 
        bool allZero =(v[0] == 0); 
        for(int i=1;i<n;i+=1){
            if(v[i] != v[i-1]){
                allZero = false; 
                break; 
            }
        }
        if(allZero){
            cout<<0<<endl; 
        }
        else{
            int zor = 0; 
            for(auto &i: v) zor ^= i; 
            if(zor == 0){
                cout<<1<<endl; 
            }
            else{
                cout<<2<<endl; 
            }
        }
	}
	return 0;
}