#include <bits/stdc++.h>
using namespace std;
signed main()
{
    string s;
    getline(cin, s);
    vector<int> v;
    int a = 0;
    for(auto c : s) {
        if(c == ',') {
            v.push_back(a);
            a = 0;
        } else {
            a = a * 10 + c - '0';
        }
    }
    v.push_back(a);
    sort(v.begin(), v.end());
    int res, ans = 0;
    cin >> res;
    for(auto x : v) {
        if(res >= x) {
            res -= x;
            ans += 1;
        }
    }
    cout << ans << endl;
    return 0;
}