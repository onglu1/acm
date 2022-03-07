#include <bits/stdc++.h>
 
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
 
using namespace std;
int n, m, a[10000009];
char c[10000009];
void work() {
    cin >> c;
    n = strlen(c);
    for(int i = 0; i < n; i++) {
        a[i] = c[i] - '0';
    }
    for(int i = 0; i < n; i++) {
        a[i] += a[i - 1];
    }
    reverse(a, a + n);
    for(int i = 0; i < n - 1; i++) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
    while(a[n - 1] >= 10) {
        a[n] = a[n - 1] / 10;
        a[n - 1] %= 10;
        n++;
    }
    for(int i = n - 1; i >= 0; i--) {
        cout << a[i] ;
    }
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 1;
    while (Case--) work();
    return 0;
}