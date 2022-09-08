#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;
const int N = 1e6 + 1009;
char s[N];
int n;
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> (s + 1);
    cin >> n;
    while(n--) {
        int l, r;
        char c, e;
        cin >> l >> r >> c >> e;
        for(int i = l; i <= r; i++) {
            if(s[i] == c) s[i] = e;
        }
    }
    cout << (s + 1) << endl;
    return 0;
}