#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const double eps = 1e-5;
const int N = 2e6 + 1009;
int n, m, a[N], g[N][2];
double f[N][2];
int check1(double mid) {
    f[1][0] = 0;
    f[1][1] = a[1] - mid;
    for(int i = 2; i <= n; i++) {
        f[i][1] = max(f[i - 1][0], f[i - 1][1]) + a[i] - mid;
        f[i][0] = f[i - 1][1];
    }
    return max(f[n][1], f[n][0]) >= 0;
}
double solver1() {
    double l = 0, r = 1e9;
    while(l + eps <= r) {
        if(check1(Mid)) l = Mid;
        else r = Mid;
    }
    return r;
}
int check2(int mid) {
    g[1][0] = 0;
    g[1][1] = (a[1] >= mid) * 2 - 1;
    for(int i = 2; i <= n; i++) {
        g[i][1] = max(g[i - 1][0], g[i - 1][1]) + (a[i] >= mid) * 2 - 1;
        g[i][0] = g[i - 1][1];
    }
    return max(g[n][1], g[n][0]) >= 1;

}
int solver2() {
    int l = 0, r = 1e9;
    while(l <= r) {
        if(check2(Mid)) l = Mid + 1;
        else r = Mid - 1;
    }
    return r;
}
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    cin >> n;
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%.5f\n%d\n", solver1(), solver2());
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}