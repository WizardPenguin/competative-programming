// problem only when all elements are same
// otherwise largest smallest others is possible reordering
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &elm : v)
            cin >> elm;
        sort(v.begin(), v.end());
        if (v[0] == v.back())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            cout << v[0] << " " << v.back() << " ";
            for (int i = 1; i < n - 1; i += 1)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }
}