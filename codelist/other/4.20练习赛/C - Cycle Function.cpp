//
// Created by onglu on 2022/4/20.
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
const double eps = 1e-8;
const int N = 1e5 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m;
double A, B, C[N], D[N], x[N], sumx[N];
void work() {
    scanf("%d%d%lf%lf", &n, &m, &A, &B);
//    cin >> n >> m >> A >> B;
//    for(int i = 1; i <= n; i++) cin >> x[i];
//    for(int j = 1; j <= m; j++) cin >> C[j] >> D[j];
    for(int i = 1; i <= n; i++) scanf("%lf", &x[i]);
    for(int j = 1; j <= m; j++) scanf("%lf%lf", &C[j], &D[j]);
    sort(x + 1, x + 1 + n);
    for(int i = 1; i <= n; i++) sumx[i] = x[i] + sumx[i - 1];
    static int cnt = 0;
    cnt++;
    printf("Case %d:\n", cnt);
//    cout << fixed << setprecision(7);
//    cout << "Case " << cnt << ": " << endl;
    for(int i = 1; i <= m; i++) {
        double ans = 0;
        if(fabs(A * C[i] - 1) < eps) {
            ans = (fabs(A * D[i] + B) + fabs(C[i] * B + D[i])) * n;
            printf("%.8f\n", ans);
//            cout << ans << endl;
        } else {
            int pos = upper_bound(x + 1, x + 1 + n, -(A * D[i] + B) / (A * C[i] - 1)) - x;
            if(A * C[i] - 1 > 0) {
                int t = pos - 1;
                ans += -(A * D[i] + B) * t - (A * C[i] - 1) * sumx[t];
                ans += (A * D[i] + B) * (n - t) + (A * C[i] - 1) * (sumx[n] - sumx[t]);
            } else {
                int t = pos - 1;
                ans += (A * D[i] + B) * t + (A * C[i] - 1) * sumx[t];
                ans += -(A * D[i] + B) * (n - t) - (A * C[i] - 1) * (sumx[n] - sumx[t]);
            }
            swap(A, C[i]); swap(B, D[i]);
            pos = upper_bound(x + 1, x + 1 + n, -(A * D[i] + B) / (A * C[i] - 1)) - x;
            if(A * C[i] - 1 > 0) {
                int t = pos - 1;
                ans += -(A * D[i] + B) * t - (A * C[i] - 1) * sumx[t];
                ans += (A * D[i] + B) * (n - t) + (A * C[i] - 1) * (sumx[n] - sumx[t]);
            } else {
                int t = pos - 1;
                ans += (A * D[i] + B) * t + (A * C[i] - 1) * sumx[t];
                ans += -(A * D[i] + B) * (n - t) - (A * C[i] - 1) * (sumx[n] - sumx[t]);
            }
            swap(A, C[i]); swap(B, D[i]);
            printf("%.8f\n", ans);
        }
    }

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    int Case = 1;
    scanf("%d\n", &Case);
    while (Case--) work();
    return 0;
}