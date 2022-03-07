#include <bits/stdc++.h>
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
const int N = 2e7 + 1009;
int n, a[N];

void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int lst = -0x3f3f3f3f, cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] > lst + 10) {
            lst = a[i] + 10;
            cnt++;
        }
    }
    cout << cnt << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while (Case--) work();
    return 0;
}
