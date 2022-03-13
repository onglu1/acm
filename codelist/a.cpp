//
// Created by onglu on 2022/2/25.
//

#include <bits/stdc++.h>
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
//const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
const int N = 5009;
//const int N = 309
int n, m, a[N];

void work() {
    cin >> n;
    for(int i = 0; i < 1 << n; i++) {
        cout << i << ":";
        for(int j = 0; j < 18; j++) {
            if(i >> j & 1) {
                cout << " " << j;
            }
        }
        cout << endl;
    }
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x = 3;
    int y = 5;
    for(int i = 3; i <= 1000; i += 11) {
        for(int j = 5; j <= 1000; j += 11) {
            if((97 * i + 4 * j * j * j)% 11 <= 10) {
                cout << (97 * i + 4 * j * j * j)% 11 << endl;

            }
        }
    }
    return 0;
}
