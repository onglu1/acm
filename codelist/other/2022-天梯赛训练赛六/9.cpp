//
// Created by onglu on 2022/3/23.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];
vector<int> v;
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    std::sort(v.begin(), v.end());
    a[1] = v[0];
    for(int i = 1; i <= n; i++) {
        a[i] = v[i - 1] + a[i - 1];
    }
    cout << "Outgoing #: " << n - n / 2 << endl;
    cout << "Introverted #: " << n / 2 << endl;
    cout << "Diff = " << (a[n] - a[n / 2] - a[n / 2]) << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//  cin >> Case;
    while (Case--) work();
    return 0;
}