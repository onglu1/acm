//
// Created by onglu on 2022/3/23.
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
string s;
char c[109][109];
void work() {
    cin >> n;
    cin.ignore();
    getline(cin, s);
    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            c[i][j] = ' ';
        }
    }
    int now = 0;
    m = ((int)s.size() - 1) / n + 1;
    for(int j = m; j >= 1 && now < s.size(); j--) {
        for(int i = 1; i <= n && now < s.size(); i++) {
            c[i][j] = s[now];
            now++;
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << c[i][j];
        }
        cout << endl;
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//  cin >> Case;
    while (Case--) work();
    return 0;
}