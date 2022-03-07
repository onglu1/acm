#include <bits/stdc++.h>
//#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int n, m, k, ans[10];
set<pair<int, int> >S;
//unordered_map<int, unordered_map<int, int> > g;
pair<int, int> v[100009];
int read() {
    char c; int num, f = 1;
    while(c = getchar(),!isdigit(c)) if(c == '-') f = -1; num = c - '0';
    while(c = getchar(), isdigit(c)) num = num * 10 + c - '0';
    return num * f;
}
void check(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) if(S.find({x + i, y + j}) != S.end()) {
            cnt++;
//            cnt += g[x + i][y + j];
        }
    }
    ans[cnt]++;
}
signed main() {

//#ifndef ONLINE_JUDGE
//    freopen("data.in", "r", stdin);
//    freopen("data.out", "w", stdout);
//#endif
    n = read(); m = read(); k = read();
//    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) {
        int x, y;
        x = read(); y = read();
        S.insert({x, y});
//        g[x][y] = 1;
        v[i] = {x, y};
    }
    for(int i = 1; i <= k; i++) {
        int x, y;
        x = v[i].first; y = v[i].second;
        for(int i = -2; i <= 0; i++) {
            for(int j = -2; j <= 0; j++) {
                int xx = x + i, yy = y + j;
                if(xx < 1 || yy < 1) continue;
                if(xx + 2 > n || yy + 2 > m) continue;
                check(xx, yy);
            }
        }
    }
    int sum = 0;
    for(int i = 1; i < 10; i++) {
        sum += ans[i] / i;
    }
    printf("%lld\n", (1ll * n - 2) * (m - 2) - sum);
//    cout << (n - 2) * (m - 2) - sum << endl;
    for(int i = 1; i < 10; i++) {
        printf("%d\n", ans[i] / i);
//        cout << ans[i] / i << endl;
    }
    return 0;
}