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
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
struct Mat {
    int n, m;
    int g[2][2];
    Mat() {
        memset(g, 0, sizeof(g));
    }
    Mat(int n, int m) : n(n), m(m) {
        memset(g, 0, sizeof(g));
    }
    int* operator[](int i) {
        return g[i];
    }
    Mat operator*(Mat &a) {
        // cerr << n << " " << m << " " << a.n << " " << a.m << " " << a[0][0] << " " << a[0][1] << endl;

        if(m != a.n) {
            // cerr << n << " " << m << " " << a.n << " " << a.m << " " << a[0][0] << " " << a[0][1] << endl;
            // cerr << m << " " << a.n << endl;
            cerr << "ERROR" << endl;
            exit(0);
        }
        Mat c(n, a.m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < a.m; j++) {
                for(int k = 0; k < m; k++) {
                    c[i][j] = (c[i][j] + 1ll * g[i][k] * a[k][j] % mod) % mod;
                }
            }
        }
        return c;
    }
    Mat operator+(Mat a) {
        if(n != a.n || m != a.m) {
            cerr << "ERROR" << endl;
            exit(0);
        }
        Mat c(n, m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                c[i][j] = (c[i][j] + a[i][j]) % mod;
            }
        }
        return c;
    }
};
Mat ltor(2, 2), rtol(2, 2), iltor(2, 2), irtol(2, 2);
int n, m, a[N];
Mat prefix[N], preinv[N];
char c[N];
// ostream &operator<<(ostream &out, Mat m) {
//     for(int i = 0; i < m.n; i++) {
//         for(int j = 0; j < m.m; j++) {
//             out << m[i][j] << " ";
//         }
//         out << endl;
//     }
//     return out;
// }
void work() {
    ltor[0][0] = 1; ltor[0][1] = 0; ltor[1][0] = 1; ltor[1][1] = 1;
    iltor[0][0] = 1; iltor[0][1] = 0; iltor[1][0] = mod - 1; iltor[1][1] = 1;
    rtol[0][0] = 1; rtol[0][1] = 1; rtol[1][0] = 0; rtol[1][1] = 1;
    irtol[0][0] = 1; irtol[0][1] = mod - 1; irtol[1][0] = 0; irtol[1][1] = 1;
    cin >> n >> m;
    cin >> (c + 1);
    prefix[0] = Mat(2, 2);
    prefix[0][0][0] = 1; prefix[0][1][1] = 1;
    preinv[0] = Mat(2, 2);
    preinv[0][0][0] = 1; preinv[0][1][1] = 1;
    for(int i = 1; i < n; i++) {
        if(c[i] == '/') {
            // cerr << ltor.n << endl;
            // cerr << prefix[i - 1].n << " " << prefix[i - 1].m << endl;
            prefix[i] = ltor * prefix[i - 1];
            preinv[i] = preinv[i - 1] * iltor;
        } else {
            prefix[i] = rtol * prefix[i - 1];
            preinv[i] = preinv[i - 1] * irtol;
        }
    }
    for(int i = 1; i <= m; i++) {
        int hs, ht, ps, pt;
        cin >> hs >> ht >> ps >> pt;
        Mat ans(2, 1);
        ans[ps][0] = 1;
        // cout << (prefix[ht - 1] * preinv[hs - 1]) << endl;
        ans = prefix[ht - 1] * preinv[hs - 1] * ans;
        cout << ans[pt][0] % mod << endl;
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