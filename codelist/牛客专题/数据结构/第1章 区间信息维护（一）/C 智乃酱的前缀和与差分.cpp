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
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
const int mod = 998244353, G = 3, Gi = 332748118;
struct Complex {double x, y;};
Complex operator+(const Complex &a, const Complex &b) {return (Complex) {a.x + b.x, a.y + b.y};}
Complex operator-(const Complex &a, const Complex &b) {return (Complex) {a.x - b.x, a.y - b.y};}
Complex operator*(const Complex &a, const Complex &b) {return (Complex) {a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};}
int Pow(int a, int p) {
    int ans = 1;
    for( ; p; p >>= 1, a = a * a % mod)
        if(p & 1)
            ans = ans * a % mod;
    return ans % mod;
}
namespace Polynomial {
    const double Pi = acos(-1.0);
    int rev[N];
    template <typename T>
    void change(T *y, int n) {
        for(int i = 0; i < n; i++)
            rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (n >> 1) : 0);
        for(int i = 0; i < n; i++)
            if(i < rev[i])
                swap(y[i], y[rev[i]]);
    }
    void NTT(int *A, int n, int type) {
        //type = 1 DFT
        //type = -1 IDFT
        change(A, n);
        for(int m = 1; m < n; m <<= 1) {
            int Wn = Pow(type == 1 ? G : Gi, (mod - 1) / (m << 1));
            for(int i = 0; i < n; i += 2 * m) {
                int w = 1;
                for(int j = 0; j < m; j++, w = 1ll * w * Wn % mod) {
                    int x = A[i + j], y = 1ll * w * A[i + j + m] % mod;
                    A[i + j] = (x + y) % mod;
                    A[i + j + m] = (x - y + mod) % mod;
                }
            }
        }
        if(type == -1) {
            int inv = Pow(n, mod - 2);
            for(int i = 0; i < n; i++)
                A[i] = 1ll * A[i] * inv % mod;
        }
    }

}
//以下代码加在主函数内

int n, k;
int A[N], B[N];

void work() {
    cin >> n >> k;
    n -= 1;
    for(int i = 0; i <= n; i++) cin >> A[i];
    if(k < 0) {
        k = -k;
        // k -= 1;
        B[0] = 1;
        for(int i = 1; i <= n; i++)
            B[i] = (-B[i - 1] * ((k - i + 1) % mod) % mod * Pow(i, mod - 2) % mod + mod) % mod;
    } else {
        B[0] = 1;
        for(int i = 1; i <= n; i++) {
            B[i] = B[i - 1] * ((k - 1 + i) % mod) % mod * Pow(i, mod - 2) % mod;
        }

    }
    // for(int i = 0; i <= n; i++) cout << B[i] << " " ;
    // cout << endl;
    int limit = 1;
    while(limit <= n + n) limit <<= 1;
    Polynomial :: NTT(A, limit, 1);
    Polynomial :: NTT(B, limit, 1);
    for(int i = 0; i < limit; i++) A[i] = (A[i] * B[i]) % mod;
    Polynomial :: NTT(A, limit, -1);
    for(int i = 0; i <= n; i++) {
        cout << (A[i] % mod + mod) % mod << " " ;
    }
    cout << endl;
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