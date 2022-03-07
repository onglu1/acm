#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, f[N];
char c[N];
const char dir[][10] = {
        "dream",
        "erase",
        "eraser",
        "mer"drea
};
int match(int l, int r, int j) {
    for(int i = l; i <= r; i++) {
        if(c[i] != dir[j][i - l]) {
            return 0;
        }
    }
    return 1;
}
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> (c + 1);
    n = strlen(c + 1);
    f[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(i >= 5) {
            f[i] |= f[i - 5] & match(i - 5 + 1, i, 0);
            f[i] |= f[i - 5] & match(i - 5 + 1, i, 1);
        }
        if(i >= 6) {
            f[i] |= f[i - 6] & match(i - 6 + 1, i, 2);
        }
        if(i >= 7) {
            f[i] |= f[i - 7] & match(i - 7 + 1, i, 3);
        }
    }
    cout << (f[n] ? "YES" : "NO") << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}