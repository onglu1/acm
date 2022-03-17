//
// Created by onglu on 2022/3/16.
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
//const int N = 309
int n, m, a[N];
int t, pre[N];
int gettime(int h, int m) {
    return h * 60 + m;
}
void work() {
    memset(pre, -1, sizeof(pre));
    int tot = 0, cnt = 0;
//    printf("%d\n", gettime(10, 0) - gettime())
    while(1) {
        int id;
        char c;
        int h, m;

        scanf("%d %c %d:%d", &id, &c, &h, &m);
//        cout << id << " " << c << " " << h << " " << m << endl;
        t = gettime(h, m);

        if(id == 0) break;
        if(c == 'E') {
            if(pre[id] != -1) {
                tot += t - pre[id];
//                printf("%d\n", t - pre[id]);
                pre[id] = -1;
                cnt += 1;
            }
        } else {
            pre[id] = t;
        }
    }
    if(cnt == 0) printf("0 0\n");
    else printf("%d %d\n", cnt, (int)(tot * 1.0 / cnt + 0.5));
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    int Case = 0;
    scanf("%d", &Case);
    while (Case--) work();
    return 0;
}