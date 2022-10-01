    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
     
    void solve()
    {
    	int n, m, k;
    	cin >> n >> m >> k;
    	string a, b;
    	cin >> a >> b;
    	string c = "";
     
    	sort(a.begin(), a.end());
    	sort(b.begin(), b.end());
     
    	int i = 0;
    	int j = 0;
    	int prev1 = 0;
    	int prev2 = 0;
    	while (i < n && j < m) {
    		if (prev1 == k) {
    			c += b[j++];
    			prev1 = 0;
    			prev2 = 1;
    		}
    		else if (prev2 == k) {
    			c += a[i++];
    			prev1 = 1;
    			prev2 = 0;
    		}
    		else {
    			if (a[i] <= b[j]) {
    				c += a[i++];
    				prev1++;
    				prev2 = 0;
    			}
    			else {
    				c += b[j++];
    				prev1 = 0;
    				prev2++;
    			}
    		}
    	}
    	cout << c << "\n";
    }
     
     
    int32_t main()
    {
    	int t = 1;
    	cin >> t;
     
    	while (t--)
    	{
    		solve();
    	}
    	return 0;
    }