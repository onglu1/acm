#include <bits/stdc++.h>
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
 
using namespace std;
void work() {
    int n, m;
    map<int, int> cnt;
    int sum = 0;
    int x, ans = 0;
    cin >> n >> m;
    cnt[0] = 1;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        sum += x;
        ans += cnt[m - sum];
        cnt[-sum]++;
    }
    cout << ans << endl;
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 1;
    while (Case--) work();
    return 0;
}