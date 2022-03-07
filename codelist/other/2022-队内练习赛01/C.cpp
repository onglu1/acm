//
// Created by onglu on 2022/3/2.
//

#include <bits/stdc++.h>
#define int long long
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
int f[20][20][20];
void work() {
    int ans = 0;
    for(int i = 1; i <= 3; i++) {
        if(a[i] > 12) {
            a[i] -= 12;
            ans += a[i] / 3; a[i] %= 3;
            a[i] += 12;
        }
    }
    cout << f[a[1]][a[2]][a[3]] + ans << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 15; i++) {
        for(int j = 0; j < 15; j++) {
            for(int k = 0; k < 15; k++) {
                if(i >= 3) f[i][j][k] = max(f[i][j][k], f[i - 3][j][k] + 1);
                if(j >= 3) f[i][j][k] = max(f[i][j][k], f[i][j - 3][k] + 1);
                if(k >= 3) f[i][j][k] = max(f[i][j][k], f[i][j][k - 3] + 1);
                if(i && j && k) {
                    f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k - 1] + 1);
                }

            }
        }
    }
    while(1) {
        for(int i = 1; i <= 3; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= 3; i++) {
            int x;
            cin >> x;
            a[i] += x;
        }
        if(a[1] + a[2] + a[3] == 0) break;
        work();
    }
    return 0;
}