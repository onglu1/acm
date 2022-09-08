//
// Created by onglu on 2022/4/30.
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
char c[N];
int oldrk[N], rk[N], sa[N], id[N], cnt[N];
void get_sa(char *c) {
    n = strlen(c + 1);
    m = 300;
    for(int i = 1; i <= n; i++) cnt[rk[i] = c[i]]++;
    for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for(int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;
    for(int w = 1; w < n; w <<= 1) {
        int tt = 0;
        for(int i = 1; i <= w; i++) id[++tt] = i + n - w;
        for(int i = 1; i <= n; i++) if(sa[i] > w) {
            id[++tt] = sa[i] - w;
        }
        memset(cnt, 0, sizeof(int) * (m + 1));
        for(int i = 1; i <= n; i++) cnt[rk[i]]++;
        for(int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
        for(int i = n; i >= 1; i--) sa[cnt[rk[id[i]]]--] = id[i];
        memcpy(oldrk, rk, sizeof(int) * (n + 1));
        int p = 1;
        rk[sa[1]] = 1;
        for(int i = 2; i <= n; i++) {
            rk[sa[i]] = (oldrk[sa[i]] == oldrk[sa[i - 1]] && oldrk[sa[i] + w] == oldrk[sa[i - 1] + w]) ? p : ++p;
        }
        if(p == n) break;
        m = p;
    }
}
void work() {
    cin >> (c + 1);
    n = strlen(c + 1);
    memcpy(c + n + 1, c + 1, sizeof(char) * (n + 1));
    get_sa(c);
    for(int i = 1; i <= n; i++) if(sa[i] <= n / 2) {
        cout << c[sa[i] + n / 2 - 1];
    }
    cout << endl;
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