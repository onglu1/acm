#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const double eps = 1e-14;
const int N = 2e6 + 1009;
struct node {
    int x;
    double d;
};
bool operator<(const node &a, const node &b) {
    return a.d > b.d;
}
priority_queue<node> q;
int n, m, a[N], s, t;
int x[N], y[N], r[N];
double dis[N];
double get(int a, int b) {
    if(r[a] + r[b] > sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b])) - eps) return 0;
    else return sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b])) - r[a] - r[b];
}
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    scanf("%lld%lld%lld%lld", x + 1, y + 1, x + 2, y + 2);
//    cin >> x[1] >> y[1] >> x[2] >> y[2];
    r[1] = r[2] = 0;
//    cin >> n;
    scanf("%lld", &n);
    n += 2;
    for(int i = 3; i <= n; i++) {
        scanf("%lld%lld%lld", x + i, y + i, r + i);
//        cin >> x[i] >> y[i] >> r[i];
    }
    s = 1; t = 2;
    for(int i = 1; i <= n; i++) dis[i] = 1e18; dis[s] = 0;
//    printf("%.10f\n", get(1, 3));
//    return 0;
    q.push({s, 0});
    while(q.size()) {
        int x = q.top().x;
        double d = q.top().d;
//        printf("%d %.10f\n", x, d);
        q.pop();
        if(d > dis[x] + eps) continue;
        for(int i = 1; i <= n; i++) if(i != x) {
            double cost = get(x, i);
            if(dis[i] > dis[x] + cost + eps) {
                dis[i] = dis[x] + cost;
                q.push({i, dis[i]});
            }
        }
    }
    printf("%.10f\n", dis[t]);
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}