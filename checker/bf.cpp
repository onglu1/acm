#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 5e3 + 10 , mod = 998244353 ;

int T , n , a[MAX_N] , cnt[MAX_N] , sum[MAX_N] , sumf[MAX_N] , jc[MAX_N] , f[MAX_N][MAX_N] ;

int main() {
    scanf("%d" , &T) ;
    for (; T-- ;) {
        scanf("%d" , &n) ;
        for (int i = 0 ; i < n ; ++i) scanf("%d" , &a[i]) ;

        ///

        int ans = 0 ;
        do {
            bool ok = 1 ;
            for (int i = 3 ; i < n && ok ; i += 2) if (a[i] <= a[i - 2]) ok = 0 ;
            for (int i = 0 ; i < n && ok ; i += 2) {
                int x = i - 1 , y = i + 1 ;
                if (x >= 0 && a[x] <= a[i]) ok = 0 ;
                if (y < n && a[y] <= a[i]) ok = 0 ;
            }

            if (ok) ++ans ;
        }while(std::next_permutation(a + 0 , a + n)) ;

        printf("%d\n" , ans) ;
    }

    return 0 ;
}