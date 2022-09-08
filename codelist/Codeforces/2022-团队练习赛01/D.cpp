#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1009;
int n, h, H;
int t[N], a[N], b[N];
int work() {
    cin >> n >> h >> H;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    int minn = 0x3f3f3f3f;
    for(int i = 1; i <= n; i++) {
        int p = a[i] % (2 * H);
        if(p <= h || p >= 2 * H - h) {
            t[i] = a[i] + b[i];
        } else {
            int d = 0;
            d = 2 * H - h - p;
            t[i] = a[i] + b[i] + d;
        }
        minn = min(minn, t[i]);
    }
    for(int i = 1; i <= n; i++) if(t[i] == minn) return i;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case ;
    cin >> Case;
    while(Case--) cout << work() << endl;
    return 0;
}