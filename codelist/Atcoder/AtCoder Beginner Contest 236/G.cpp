//
// Created by onglu on 2022/3/22.
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
int n, m;
int l;
struct mat {
    int n;
    int g[109][109];
};
mat operator*(const mat &a, const mat &b) {
    mat c;
    int n = a.n;
    c.n = a.n;
    for(int i = 1; i <= n; i++) {
        memset(c.g[i], 0x3f, sizeof(int) * (c.n + 5));
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                c.g[i][j] = min(c.g[i][j], max(a.g[i][k], b.g[k][j]));
            }
        }
    }
    return c;
}
mat Pow(mat &a, int p) {
    mat ans;
    int f = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            ans.g[i][j] = 0x3f3f3f3f;
        }
        ans.g[i][i] = 0;
    }
    for( ; p; p = p >> 1, a = a * a) {
        if(p & 1) {
            ans = a * ans;
        }
    }
    return ans;
}
void work() {
    mat a;
    cin >> n >> m >> l;
    a.n = n;
    memset(a.g, 0x3f, sizeof(a.g));

    for(int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        a.g[y][x] = min(a.g[y][x], i);
    }
    a = Pow(a, l);
    for(int i = 1; i <= n; i++) {
        if(a.g[i][1] == 0x3f3f3f3f) {
            cout << -1 << " " ;
        } else {
            cout << a.g[i][1] << " ";
        }
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
//  cin >> Case;
    while (Case--) work();
    return 0;
}