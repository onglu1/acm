//
// Created by onglu on 2022/4/2.
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
//const int N = 309;
int n, m, a[N], tot[N], ac[N];
const int l[] ={11 * 60, 18 * 60, 21 * 60};
const int r[] ={15 * 60, 21 * 60, 26 * 60};
const char* q[] = {
        "lunch",
        "dinner",
        "midnight"
};
void work() {
    for(int i = 0; i < 3; i++) ac[i] = tot[i] = 0;
    for(int i = 1; i <= n; i++) {
        int hh, mm, t;
        scanf("%d:%d %d", &hh, &mm, &t);
        if(hh < 7) hh += 24;
        int tt = hh * 60 + mm;
        for(int j = 0; j < 3; j++) {
            if(l[j] <= tt && tt < r[j]) {
                tot[j]++;
                if(t < mm) t += 60;
                if(t - mm <= 8) ac[j]++;
            }
        }
    }
    for(int i = 0; i < 3; i++) {
        printf("%s", q[i]);
        if(tot[i] == 0) printf(" no guest\n");
        else printf(" %d\n", 100 * ac[i] / tot[i]);
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(scanf("%d", &n) == 1) {
        if(n == 0) break;
        work();
    }
    return 0;
}