#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m;
struct node {
    int x, y;
} a[N];
int l[N], r[N];
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y;

    }
    for(int i = 1; i <= n; i++) l[i] = r[i] = i;
    sort(a + 1, a + 1 + m, [](const node &a, const node &b) {
        return a.x < b.x;
    });
    for(int i = 1; i <= m; i++) {
        int t = a[i].y;
        int ll = min(l[t], l[t + 1]);
        int rr = max(r[t], r[t + 1]);
        l[t] = l[t + 1] = ll;
        r[t] = r[t + 1] = rr;
//        cout << t << " " << l[t] << " " << r[t] << endl;
    }
    for(int i = 1; i <= n; i++){
        cout << r[i] - l[i] + 1 << " ";
    }
    cout << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}