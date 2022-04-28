#include <bits/stdc++.h>
using  namespace std;
const int N = 2e5 + 1009;
int n, a[N];
void work() {
    cin >> n;
    for(int i = n; i >= 1; i--) cin >> a[i];
    int ans = 0;
    for(int i = 1; i < n; i = i * 2) {
        while(i + 1 <= n && a[i + 1] == a[1]) i++;
        int cnt = 0;
        for(int j = i + 1; j <= min(n, i * 2); j++) {
            cnt |= a[j] != a[1];
        }
        ans += cnt;
    }
    cout << ans << endl;

}
signed main()
{
    ios ::sync_with_stdio(0);
    cin.tie(0);
    int Case;
    cin >> Case;
    while(Case--) work();
    return 0;
}