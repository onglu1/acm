//
// Created by onglu on 2022/3/13.
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
int f[N][3];
string s;
int get(int n) {
    return f[n][0] + f[n][1] + f[n][2] + f[n][3];
}
void work() {
    cin >> s; n = s.size();
    f[0][0] = 1;
    f[0][1] = 1;
    for(int i = 1; i < n; i++) {
        f[i][0] = f[i - 1][0];
        for(int j = 1; j <= 3; j++) {
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
        }
        for(int j = 0; j <= 3; j++) {
            for(int k = 1; k <= j && i - k >= 0; k++) if(s[i - k] == s[i]){
                f[i][j] -= f[i - k][j - k];
                break;
            }
        }
    }
    cout << f[3][2] << endl;
    cout << get(n - 1) << endl;
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