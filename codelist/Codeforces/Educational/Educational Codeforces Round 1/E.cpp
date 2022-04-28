//
// Created by onglu on 2022/4/24.
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
int n, m, a[N];
int f[31][31][51];
void init() {
    for(int i = 1; i <= 30; i++) {
        for(int j = 1; j <= 30; j++) {
            for(int k = 1; k <= min(i * j, 50); k++) {
                if(k == i * j) {
                    f[i][j][k] = 0;
                    continue
                }
            }
        }
    }
}
void work() {

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}