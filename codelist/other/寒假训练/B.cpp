#include <bits/stdc++.h>
#define int long long
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, a[N];
void add(int l, int r, int x) {
    a[l] += x;
    a[r + 1] -= x;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        char opt;
        int l, r;
        cin >> opt >> l >> r;
        if(opt == 'R') {
            add(l, l, 1);
            add(r + 1, r + 1, -1);
        } else if(opt == 'D') {
            add(l, l, -1);
            add(r + 1, r + 1, 1);
        } else if(opt == 'H') {
            if((r - l + 1) % 2 == 0) {
                add(l, l + (r - l + 1) / 2 - 1, 1);
                add(l + (r - l + 1) / 2 + 1, r + 1, -1);
            } else {
                add(l, l + (r - l + 1) / 2, 1);
                add(l + (r - l + 1) / 2 + 1, r + 1, -1);
            }
        } else {
            if((r - l + 1) % 2 == 0) {
                add(l, l + (r - l + 1) / 2 - 1, -1);
                add(l + (r - l + 1) / 2 + 1, r + 1, 1);
            } else {
                add(l, l + (r - l + 1) / 2, -1);
                add(l + (r - l + 1) / 2 + 1, r + 1, 1);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
    }
    for(int i = 1; i <= n; i++) {
        cout << a[i] << endl;
    }
    return 0;
}