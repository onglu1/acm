#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 1009;
int n, a, b, p[N];

signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    int minn = 0;
    for(int i = 2; i <= n; i++) {
        minn += min(b, (p[i] - p[i - 1]) * a);
    }
    cout << minn << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}