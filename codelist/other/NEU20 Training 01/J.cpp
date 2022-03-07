#include <bits/stdc++.h>
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
int l, r;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(scanf("%lld%lld", &l, &r)) {
        if(l == 0 && r == 0) return 0;
        double ans = 0;
        for(int i = l; i <= r; i++) {
            ans += pow(i, -2.0 / 3);
        }
        ans /= 3;
        int base = -15;
        while(ans < 1) {
            ans = ans * 10;
            base = base - 1;
        }
        while(ans >= 10) {
            ans = ans / 10;
            base = base + 1;
        }
        printf("%.5fE", ans);
        if(base < 0) printf("-"), base = -base;
        printf("%03d\n", base);
    }
    return 0;
}
