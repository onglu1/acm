#include <bits/stdc++.h>

#define db double

const db eps = 1e-11 ;
const int MAX_N = 100 + 10 ;

int n , m , k ;
bool ed[MAX_N] ;
db p , A[MAX_N][MAX_N] ;

void gauss() {
    for (int i = 0 ; i < m ; ++i) {
        int r = i ;
        for (int j = i + 1 ; j < m ; ++j) if (fabs(A[r][i]) - fabs(A[j][i]) < eps) r = j ;
        if (r != i) for (int j = 0 ; j <= m ; ++j) std::swap(A[r][j] , A[i][j]) ;

        for (int j = i + 1 ; j < m ; ++j) {
            db t = A[j][i] / A[i][i] ;
            for (int k = i ; k <= m ; ++k) A[j][k] -= t * A[i][k] ;
        }
    }

    for (int i = m - 1 ; i >= 0 ; --i) {
        for (int j = i + 1 ; j < m ; ++j) A[i][m] -= A[i][j] * A[j][m] ;
        A[i][m] /= A[i][i] ;
    }
}

int main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    scanf("%d %d %lf" , &n , &k , &p) ;

    m = (1 << n) ;
    for (int i = 0 ; i < m ; ++i) {
        int cnt = 0 ;
        for (int j = 0 ; j < n ; ++j) if ((1 << j) & i) ++cnt ;

        if (cnt >= k) ed[i] = true ;
    }

    for (int i = 0 ; i < m ; ++i) {
        A[i][i] = 1 ;
        if (ed[i]) continue ;

        A[i][m] = 1 ;
        for (int j = 0 ; j < 2 ; ++j) {
            int ni = (i << 1) & (m - 1) | j ;

            if (j) A[i][ni] -= p ;
            else A[i][ni] -= 1 - p ;
        }
    }
    gauss() ;

    printf("%0.8f\n" , A[0][m]) ;

    return 0 ;
}