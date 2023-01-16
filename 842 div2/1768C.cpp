#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &elm : v)
        cin >> elm;
    vector<int> a(n, 0), b(n, 0);
    set<int> ta, tb;
    for (int i = 1; i <= n; i += 1)
    {
        ta.insert(i), tb.insert(i);
    }
    for (int i = 0; i < n; i += 1)
    {
        auto elm = v[i];
        if (ta.find(elm) != ta.end())
        {
            a[i] = elm;
            ta.erase(elm);
        }
        else if (tb.find(elm) != tb.end())
        {
            b[i] = elm;
            tb.erase(elm);
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }
    // for (auto &elm : a)
    //     cerr << elm << " ";
    // cerr << endl;
    // for (auto &elm : b)
    //     cerr << elm << " ";
    // cerr << endl;
    // now it's time to insert remaining elements
    auto insert = [&](set<int> &other, vector<int> &cur, vector<int> &oth)
    {
        vector<int> id;
        for (int i = 0; i < n; i += 1)
        {
            if (cur[i] and not oth[i])
            {
                id.push_back(i);
            }
        }
        // now taking smaller to largest insertion of values of other set
        sort(id.begin(), id.end(), [&](int x, int y)
             { return a[x] < a[y]; });
        // cerr << "sorted id" << endl;
        // for (auto &i : id)
        //     cerr << i << " ";
        // cerr << endl;
        for (auto &elm : id)
        {
            // now take largest number smaller than cur[elm] at this place
            auto it = other.upper_bound(cur[elm]);
            if (it == other.begin())
                return false;
            it--;
            oth[elm] = *it;
            other.erase(it);
        }
        return true;
    };
    if (insert(tb, a, b) and insert(ta, b, a))
    {
        cout << "YES" << endl;
        for (auto &elm : a)
            cout << elm << " ";
        cout << endl;
        for (auto &elm : b)
            cout << elm << " ";
        cout << endl;
        return;
    }
    cout << "NO" << endl;
}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
}