//
// Created by onglu on 2022/3/12.
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
int n, m;

int a, b, c, d, e, cnt[2] = {0};
int win(int x) {
    if(x == 0) cout << "The winner is a: " << a << " + " << cnt[0] << endl;
    else cout << "The winner is b: " << b << " + " << cnt[1] << endl;
    exit(0);
}
void work() {
    cin >> a >> b >> c >> d >> e;
    cnt[c] += 1;
    cnt[d] += 1;
    cnt[e] += 1;
    if(a > b) {
        if(cnt[0]) win(0);
        else win(1);
    }
    if(a < b) {
        if(cnt[1]) win(1);
        else win(0);
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}