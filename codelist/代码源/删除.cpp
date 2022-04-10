//
// Created by onglu on 2022/4/4.
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
int n, m, a[N], b[N];

void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        b[i] = a[i + 1] - a[i];
    }
    n -= 1;
    int ans = 0
    for(int i = 1; i <= n; i++) {
        if(b[i] == 0) ans++;
        while(i <= n && b[i] == 0) i++;
        if(i <= n) {
            int j = i + 1;
            while(j <= n && b[j] != 0 && (b[j] > 0) == (b[i] > 0)) j++;
            ans += getans(i, j - 1, b[i] < 0);
            i = j;
        }
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
//    cin >> Case;
    while (Case--) work();
    return 0;
}