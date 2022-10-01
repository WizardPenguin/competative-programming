#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {
	// use each letter atlest once 
	// no 2 adjacent characters should be equal 
	int test; 
	cin>>test; 
	while(test--){ 
		int n,k; 
		cin>>n>>k; 
		if(n == k){
			for(int i=0;i<k;i+=1){
                cout<<char(i + 'a'); 
            }
		}
		else if(n < k){
			cout<<-1;  
		}
		else{
			int a = 1; 
			int i=0;
			for(i=0;n-i-1 >= k-2;i+=1){
				if(a) cout<<'a'; 
				else cout<<'b'; 
				a = 1-a; 
			}
			int x = 2; 
			while(i<n){
				cout<<char(x + 'a'); 
				x += 1; 
                i+=1; 
			}
		}
		cout<<endl; 
	}
	// Your code here
	return 0;
}