//
// Created by onglu on 2022/2/26.
//

#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
const int N = 309;
int cnt[30][N];
int n, m, g[N][N], p[N];
char s[N];
int query(int l, int r, char c) {
    if(l > r) return 0;
    return cnt[c - 'a'][r] - cnt[c - 'a'][l - 1];
}
int tree[N];
void add(int x, int y) {
    for( ; x <= N; x += x & -x)
        tree[x] += y;
}
int query(int x) {
    int ans = 0;
    for( ; x; x -= x & -x)
        ans += tree[x];
    return ans;
}
void work() {
    cin >> (s + 1);
    n = strlen(s + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 26; j++) cnt[j][i] = cnt[j][i - 1];
        cnt[s[i] - 'a'][i] += 1;
    }
    for(int i = 1; i <= n; i++) {
        g[i][i] = 1;
        g[i][i - 1] = 1;
    }
    for(int len = 2; len <= n; len++) {
        for(int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            g[i][j] = (s[i] == s[j]) && (g[i + 1][j - 1]);
        }
    }
    for(int i = 1; i <= n; i++) {
        p[i] = -1;
        for(int j = n; j >= i; j--) {
            if(g[i][j]) {
                p[i] = j;
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(p[i] == -1) continue;
        if(query(n) - query(p[i] - 1)) continue;
        ans += 1;
        add(p[i], 1);
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
    while (Case--) work();
    return 0;
}