//
// Created by onglu on 2022/3/22.
//

#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 250 + 10 , mod = 998244353 ;

int n , k , f[MAX_N][MAX_N][MAX_N] , g[MAX_N][MAX_N] ;

int qpow(int a , int t) {
    int s = 1 ;
    for (; t ; t >>= 1 , a = (ll)a * a % mod)
        if (t & 1) s = (ll)s * a % mod ;

    return  s ;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\MerCI\\Desktop\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\MerCI\\Desktop\\acm\\data.out", "w", stdout);
#endif

    scanf("%d %d" , &n , &k) ;
    for (int i = 1 ; i <= k ; ++i) f[1][i][1] = g[1][i] = 1 ;
    for (int i = 2 ; i < n ; ++i) {
        for (int j = 1 ; j <= k ; ++j) {
            for (int p = 2 ; p <= i ; ++p)
                f[i][j][p] = (ll)f[i - 1][j][p - 1] * qpow(k + 1 - j , i - 1) % mod * qpow(p , mod - 2) % mod ;

            f[i][j][1] = 0 ;
            for (int p = 1 ; p < j ; ++p)
                f[i][j][1] = ((ll)g[i - 1][p] * qpow(k + 1 - j , i - 1) % mod + f[i][j][1]) % mod ;

            g[i][j] = 0 ;
            for (int p = 1 ; p <= i ; ++p) (g[i][j] += f[i][j][p]) %= mod ;
        }
    }

    int jc = 1 , ans = 0 ;
    for (int i = 1 ; i < n ; ++i) jc = (ll)jc * i % mod ;
    for (int i = 1 ; i <= k ; ++i)
        for (int j = 1 ; j <= n ; ++j) {
            int tmp = (ll)jc * f[n - 1][i][j] % mod ;
            (ans += tmp) %= mod ;
        }

    printf("%d\n" , ans) ;

    return 0;
}