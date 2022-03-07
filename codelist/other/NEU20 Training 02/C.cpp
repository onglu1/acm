#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const double eps = 1e-5;
struct node {
    int x, a, id;
    double l, ans;
} a[3];
int n;
double getcr(double a, double b, double c) {
//    assert(2.0 * c * b > eps);
    double cs = (b * b + c * c - a * a) / (2.0 * b * c);
//    cout << "cs : "  << cs << endl;
    double sn = sqrt(1.0 - cs * cs);
    double bt = b * sn;
    return bt;
}
double cal(double a, double b, double c) {
//    assert(2.0 * a * b > eps);
    double cs = (a * a + b * b - c * c) / (2.0 * a * b);
    double t = sqrt(b * b + 4.0 / 9 * a * a - 4.0 / 3 * b * a * cs);
//    cout << "a : " << a << endl;
//    cout << "b : " << b << endl;
//    cout << "c : " << c << endl;
    double bt = getcr(a * 2.0 / 3, b, t);
//    cout << b * b - bt * bt << endl;
    return sqrt(b * b - bt * bt);
}
void work() {
    int Case = 0;
    scanf("%d%d%d%d%d%d", &a[0].x, &a[1].x, &a[2].x, &a[0].a, &a[1].a, &a[2].a);
    a[0].id = 0; a[1].id = 1; a[2].id = 2;
    sort(a, a + 3, [](const node &a, const node &b) {return a.x < b.x;});
    for(int i = 0; i < 3; i++) {
        a[i].l = sqrt((a[(i + 1) % 3].a * a[(i + 1) % 3].a
                + a[(i + 2) % 3].a * a[(i + 2) % 3].a - a[i].a * a[i].a / 2.0) / 2);
    }
//    cout << a[0].a << endl;
    a[0].ans = a[0].x;
    double bt = getcr(a[0].a * 0.5, a[2].a, a[0].l);
    double Side = sqrt(a[0].a * a[0].a * 0.25 - bt * bt) + a[0].x + a[0].l;
    double xx = Side * Side + bt * bt;
    if(xx < a[1].x * a[1].x - eps) {
        swap(a[1], a[2]);
        bt = getcr(a[0].a * 0.5, a[2].a, a[0].l);
        Side = sqrt(a[0].a * a[0].a * 0.25 - bt * bt) + a[0].x + a[0].l;
        xx = Side * Side + bt * bt;
        if(xx < a[1].x * a[1].x - eps) {
            Case = 2;
        } else Case = 1;
    } else Case = 1;
    double lmid;
    if(Case == 1) {
        lmid = 0.5 * (a[0].x * a[0].x + a[1].x * a[1].x - a[2].a * a[2].a * 0.5);
        lmid = sqrt(lmid);
        if(lmid + a[2].l < a[2].x - eps) {
            Case++;
            a[2].ans = lmid + bt;
        }
    }
    switch (Case) {
        case 0:
            lmid = 0.5 * (a[1].x * a[1].x + a[2].x * a[2].x - a[0].a * a[0].a * 0.5);
            lmid = sqrt(lmid);
//            cout << "lmid : " << lmid << endl;
//            cout << "a[0].l : " << a[0].l << endl;
//            cout << "a[0].x  : " << a[0].x << endl;
            a[0].ans = cal(a[0].l, a[0].x, lmid);

            lmid = 0.5 * (a[0].x * a[0].x + a[2].x * a[2].x - a[1].a * a[1].a * 0.5);
            lmid = sqrt(lmid);
            a[1].ans = cal(a[1].l, a[1].x, lmid);

            lmid = 0.5 * (a[0].x * a[0].x + a[1].x * a[1].x - a[2].a * a[2].a * 0.5);
            lmid = sqrt(lmid);
            a[2].ans = cal(a[2].l, a[2].x, lmid);

            break;
        case 1:
            lmid = 0.5 * (a[0].x * a[0].x + a[1].x * a[1].x - a[2].a * a[2].a * 0.5);
            lmid = sqrt(lmid);
            bt = getcr(a[2].a / 2.0, a[1].x, lmid);
            a[1].ans = sqrt(a[1].x * a[1].x - bt * bt);
            bt = getcr(a[2].a / 2.0, a[0].x, lmid);
            a[0].ans = sqrt(a[0].x * a[0].x - bt * bt);
            break;
        case 2:
            break;
    }
    sort(a, a + 3, [](const node &a, const node &b) {return a.id < b.id;});
    for(int i = 0; i < 3; i++) {
        printf("-%.10f%c", a[i].ans, i == 2 ? '\n' : ' ');
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    int Case = 0;
    scanf("%d", &Case);
    while (Case--) work();
    return 0;
}