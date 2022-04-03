//
// Created by onglu on 2022/3/19.
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
//const int N = 309
int n, m, a[N];
char c;
void work() {
    cin >> n >> c;
    string s;
    cin.ignore();
    getline(cin, s);
    for(int i = 1; i <= n - (int)s.size(); i++) {
        cout << c;
    }
    if(s.size() > n) {
        for(int i = s.size() - n; i < s.size(); i++) {
            cout << s[i];
        }
    } else {
        cout << s << endl;
    }
//    cout << s << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}