#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, a[N];
struct node {
    int k, d;
} p[4];
struct Point {
    int x, y, z;
};
vector<Point> v;
int g[109][109];
void work() {
    int res = p[1].k;
    for(int i = 1; i <= p[3].k; i++) {
        v.push_back({i, i, 0});
        g[i][i] = 1;
        res--;
    }
    for(int i = p[3].k + 1; i <= p[2].k; i++) {
        v.push_back({p[3].k, i, 0});
        g[i][p[3].k] = 1;
        res--;
    }
    for(int i = 1; i <= p[2].k && res; i++) {
        for(int j = 1; j <= p[3].k && res; j++) {
            if(g[i][j] == 0) {
                v.push_back({i, j, 0});
                res--;
            }
        }
    }
    cout << v.size() << endl;
//    cout << p[1].d << endl;
    for(auto x : v) {
        Point t;
        if(p[1].d == 1) t.z = x.z;
        else if(p[1].d == 2) t.y = x.z;
        else t.x = x.z;

        if(p[2].d == 1) t.z = x.x;
        else if(p[2].d == 2) t.y = x.x;
        else t.x = x.x;

        if(p[3].d == 1) t.z = x.y;
        else if(p[3].d == 2) t.y = x.y;
        else t.x = x.y;


        cout << t.x << " " << t.y << " " << t.z << endl;
    }


}

signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 1; i <= 3; i++) {
        cin >> p[i].k;
        p[i].d = i;
    }
    sort(p + 1, p + 1 + 3, [](const node &a, const node &b) {
        return a.k > b.k;
    });
    if(p[1].k > p[2].k * p[3].k) {
        cout << -1 << endl;
        return 0;
    }
    work();
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}
/*
 * d = 1, z
 * d = 2, y
 * d = 3, x
 *
 */