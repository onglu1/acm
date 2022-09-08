//
// Created by onglu on 2022/5/13.
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
int n, m, a[N], need[N];
char c[N];
void work() {
    cin >> (c + 1);
    n = strlen(c + 1);
    int ans = n + 1, suf = 0;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += c[i] == 'R' ? -1 : 1;
        need[i] = max(need[i - 1], -sum);
    }
    int cnt = 0;
    for(int i = n; i > 0; i--) {
        if(c[i] == 'R') {
            suf = min(suf - 1, -1);
            cnt -= 1;
        } else {
            suf += 1;
            cnt += 1;
        }
        if(suf < 0) continue;
        if(cnt >= need[i - 1]) {
            ans = min(ans, i - 1);
        }
    }
    cout << ans << endl;
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
    while (Case--) work();
    return 0;
}