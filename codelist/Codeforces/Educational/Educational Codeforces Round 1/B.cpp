//
// Created by onglu on 2022/4/24.
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
char c[100009];
char t[100009];
void work() {
    cin >> c;
    cin >> n;
    while(n--) {
        int l, r, k;
        cin >> l >> r >> k;
        l -= 1;
        r -= 1;
        k %= (r - l + 1);
        for(int i = l; i <= r; i++) t[i] = c[i];
        memcpy(c + l + k, t + l, sizeof(char) * (r - l + 1 - k));
        memcpy(c + l, t + r - k + 1, sizeof(char) * (k));
    }
    cout << c << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}