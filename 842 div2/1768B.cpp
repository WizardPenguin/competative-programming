// start with 1 and iterate from 1 to n weather they are in sorted order or not
// it they are not
// then we have to give this element for sorting and put it in stack of sorting till we found k elements

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (auto &elm : v)
            cin >> elm;
        int elm = 1;
        for (int i = 0; i < v.size(); i += 1)
        {
            if (elm == v[i])
                elm += 1;
        }
        // now we know count of unsorted elements
        cout << (n - elm + 1 + k - 1) / k << endl;
    }
}