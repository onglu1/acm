#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    getline(cin, s);

    map<string,int>mp;
    s += ',';
    int len = s.size();
    string t = "";
    int num = 0;
    for (int i = 0; i < len; i++) {
        if (t != "" && num != 0) {
            mp[t] += num;
            t = "";
            num = 0;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            t += s[i];
        } else if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        }
    }
    int tt;
    cin >> tt;
    while (tt--) {
        string ttt;
        cin >> ttt;
        cout << mp[ttt] << "\n";
    }
}