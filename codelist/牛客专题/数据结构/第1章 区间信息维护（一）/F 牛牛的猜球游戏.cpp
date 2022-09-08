//
// Created by onglu on 2022/5/29.
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
const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
struct SP {
    int t[10];
    SP() {
        for(int i = 0; i < 10; i++) t[i] = i;
    }
    SP(int a, int b) {
        for(int i = 0; i < 10; i++) t[i] = i;
        t[a] = b; t[b] = a;
    }
};
SP operator*(const SP &a, const SP &b) {
    SP c;
    for(int i = 0; i < 10; i++)
        c.t[i] = a.t[b.t[i]];
    return c;
}
int n, m, a[N], b[N];
int k;
SP st[N][26];
ostream &operator<<(ostream& out, const SP &c) {
    for(int i = 0; i < 10; i++) {
        out << c.t[i] << " ";
    }
    return out;
}
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    for(int i = 1; i <= n; i++) {
        st[i][0] = SP(a[i], b[i]);
    }
    for(int i = 1; i <= 18; i++) {
        for(int j = 1; j + (1 << i) - 1 <= n; j++) {
            // if(i == 2 && j == 1) {
            //     cout << "ttttt" << endl;
            //     cout << st[j][i - 1] << endl;
            //     cout << st[j + (1 << (i - 1))][i - 1] << endl;
            // }
            st[j][i] = st[j][i - 1] * st[j + (1 << (i - 1))][i - 1];
        }
    }
    // cout << st[3][0] << endl;
    // cout << st[3][1] << endl;
    // // cout << st[5][0] << endl;
    // SP ans;
    // for(int i = 1; i <= 4; i++) {
    //     ans = ans * st[i][0];
    // }
    // cout << endl;
    // cout << st[1][2] << endl;
    // cout << ans << endl << endl;
    // cout << endl;
    for(int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        SP now;
        for(int j = 18; j >= 0; j--) {
            if(l + (1 << j) - 1 <= r) {
                now = now * st[l][j];
                l += (1 << j);
            }
        }
        // now = now * st[l][0];
        cout << now << endl;
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
    while(Case--) work();
    return 0;
}