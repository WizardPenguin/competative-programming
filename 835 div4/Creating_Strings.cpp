#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    set<string> res;
    sort(s.begin(), s.end());
    do
    {
        res.insert(s);
    } while (next_permutation(s.begin(), s.end()));
    cout << res.size() << endl;
    for (auto &str : res)
        cout << str << endl;
}