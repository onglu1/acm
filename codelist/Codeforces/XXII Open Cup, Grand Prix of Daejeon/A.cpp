//
// Created by onglu on 2022/4/3.
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
//const int N = 2e6 + 1009;
const int N = 5e5 + 1009;
//const int N = 5009;
//const int N = 309;
struct node {
    int x, y;
};
const int B = 250010;
int n, m;
int x[2][N * 4], y[2][N * 4], minn[N * 4];
void update(int rt) {
    for(int i = 0; i < 2; i++) {
        x[i][rt] = min(x[i][lson], x[i][rson]);
        y[i][rt] = min(y[i][lson], y[i][rson]);
    }
    minn[rt] = min({minn[lson], minn[rson], y[0][lson] + y[1][rson], x[1][lson] + x[0][rson]});
}
void build(int l, int r, int rt) {
    if(l == r) {
        for(int i = 0; i < 2; i++) {
            x[i][rt] = 0x3f3f3f3f;
            y[i][rt] = 0x3f3f3f3f;
        }
        minn[rt] = 0x3f3f3f3f;
        return ;
    }
    build(l, Mid, lson); build(Mid + 1, r, rson);
    update(rt);
}
void modify(int l, int r, int rt, int f, int a, int b, int pos) {
    if(l == r) {
        x[f][rt] = a;
        y[f][rt] = b;
        minn[rt] = min(y[0][rt] + y[1][rt], x[1][rt] + x[0][rt]);
        return ;
    }
    if(pos <= Mid) modify(l, Mid, lson, f, a, b, pos);
    else modify(Mid + 1, r, rson, f, a, b, pos);
    update(rt);
}
multiset<int> Sx[2][N], Sy[2][N];
void work() {
    cin >> n;
    build(1, N, 1);
    while(n--) {
        int opt, f, xx, yy;
        cin >> opt >> f >> xx >> yy;
        f -= 1;
        int pos = f ? yy - xx : xx - yy;
        pos += B;
        if(opt == 1) {
            Sx[f][pos].insert(xx);
            Sy[f][pos].insert(yy);
            modify(1, N, 1, f, *Sx[f][pos].begin(), *Sy[f][pos].begin(), pos);
        } else {
            Sx[f][pos].erase(Sx[f][pos].find(xx));
            Sy[f][pos].erase(Sy[f][pos].find(yy));
            int a, b;
            a = Sx[f][pos].empty() ? 0x3f3f3f3f : *Sx[f][pos].begin();
            b = Sy[f][pos].empty() ? 0x3f3f3f3f : *Sy[f][pos].begin();
            modify(1, N, 1, f, a, b, pos);
        }
        if(minn[1] > N) {
            cout << -1 << endl;
        } else {
            cout << minn[1] << endl;
        }
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}