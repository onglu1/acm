#include <bits/stdc++.h>
#define Mid ((l + r) / 2)
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5 + 1009;
int n, a[N];
int check(int mid) {
    int l = a[1] - mid;
    int maxn = 0;
    for (int i = 2; i <= n; i++) {
        l += 1;
        if (a[i] + mid < l) return false;
        l = max(l, a[i] - mid);
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = 0, r = 1e9 + 7;
    while (l <= r) {
        if (check(Mid)) r = Mid - 1;
        else l = Mid + 1;
    }
    cout << l << endl;
    return 0;
}