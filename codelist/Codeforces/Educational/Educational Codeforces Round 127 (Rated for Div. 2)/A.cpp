//
// Created by onglu on 2022/4/22.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N];

bool work() {
    string s;
    cin >> s;
    char lst = s[0];
    int cnt = 0;
    if(s.size() == 1) return false;
    for(int i = 1; i + 1 < s.size(); i++) {
        if(s[i] != s[i - 1] && s[i] != s[i + 1]) {
            return false;
        }
    }
    if(s[0] != s[1]) return false;
    if(s[s.size() - 1] != s[s.size() - 2]) return false;
    return true;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    cin >> Case;
    while (Case--) {
        cout << (work() ? "YES" : "NO") << endl;
    }
    return 0;
}