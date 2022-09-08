//
// Created by onglu on 2022/5/13.
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
//const int N = 309;
int n, m, a[N];
int k, s, cnt;
vector<int> v;
int now = 1, pos = 0;
int t = s, minl = 0, maxr = 0;
void update(int x) {
    pos += x;
    minl = min(minl, pos);
    maxr = max(maxr, pos);
}
void work() {
    cin >> n >> k;
    s = 0;
    for(int i = 1; i <= n; i++) cin >> a[i], s += a[i];
    v.clear();
    for(int i = 1; i <= n; i++) {
        if(v[i] == 0) {
            v.push_back(i);
        }
    }
    if(abs(s) > v.size() * k) {
        cout << -1 << endl;
        return ;
    }
    now = 1, pos = 0;
    t = s, minl = 0, maxr = 0;
    for(int i = 0; i < v.size(); i++) {
        for( ; now < pos; now++) {
            update(a[now]);
        }
        now += 1;
        if(abs(pos + k) <= k * (v.size() - i - 1)) {
            update(k);
        } else {

        }
    }


}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}