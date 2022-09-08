//
// Created by onglu on 2022/5/7.
//

#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 2e3 + 10 , LG = 3 , lgN = LG + 5 , mod = 1e9 + 7 ;

ll l , r , z ;
int n , m , jc[MAX_N] , ny[MAX_N] , f[lgN][MAX_N] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;
    return s ;
}

int C(int n , int m) {
    return (ll)jc[n] * ny[m] % mod * ny[n - m] % mod ;
}

int calc(int x) {
    for (int i = LG ; i >= 0 ; --i)
        for (int j = 0 ; j <= m ; ++j) f[i][j] = 0 ;
    f[LG][0] = 1 ;
    for (int i = LG ; i ; --i) {
        int ned = z & (1LL << i) ? 1 : 0 ;
        for (int j = 0 ; j <= m ; ++j)
            for (int k = 0 ; k <= std::min(n , j) ; ++k) {
                if ((k & 1) != ned) continue ;
                int xs = C(n , k) , hav = (x & (1 << (i - 1))) ? 1 : 0 ;

                printf("%d %d %d %d %d\n" , i , j , f[i][j] , k , xs) ;

                int nj = ((j - k) << 1) + hav ;
                if (nj > m) continue ;
                f[i - 1][nj] = (f[i - 1][nj] + (ll)f[i][j] * xs % mod) % mod ;
            }
    }

    int res = 0 ;
    for (int i = 0 ; i <= n ; ++i) {
        int ned = (z & 1) ? 1 : 0 ;
        if ((i & 1) != ned) continue ;
        int xs = C(n , i) ;
        res = (res + (ll)xs * f[0][i]) % mod ;
    }
}

void work() {
    scanf("%d %d %d %d" , &n , &l , &r , &z) ;

    m = n << 1 ; jc[0] = 1 ;
    for (int i = 1 ; i <= m ; ++i) jc[i] = (ll)jc[i - 1] * i % mod ;
    ny[m] = qpow(jc[m] , mod - 2) ;
    for (int i = m - 1 ; i >= 0 ; --i) ny[i] = (ll)ny[i + 1] * (i + 1) % mod ;

    ///

    int p1 = calc(r) , p2 = calc(l - 1) ;
    printf("%d %d\n" , p1 , p2) ;
    p1 = (p1 - p2 + mod) % mod ;
    printf("%d\n" , p1) ;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}