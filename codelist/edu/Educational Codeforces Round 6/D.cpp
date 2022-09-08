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
#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N], b[N];
int s;
int ansv, anst, ansa[5], ansb[5];
map<int, pair<int, int> > M;
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], s += a[i];
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> b[i], s -= b[i];
    ansv = abs(s);
    anst = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(abs(s - 2 * a[i] + 2 * b[j]) < ansv) {
                ansv = abs(s - 2 * a[i] + 2 * b[j]);
                anst = 1;
                ansa[1] = i;
                ansb[1] = j;
            }
        }
    }
    for(int i = 1; i <= m; i++) for(int j = i + 1; j <= m; j++) {
        M[b[i] + b[j]] = {i, j};
    }
    for(int i = 1; i <= n; i++) for(int j = i + 1; j <= n; j++) {
        int ta = 2 * (a[i] + a[j]);
//        if(i == 1 && j == 4) cout << "check : " << ta << endl;
        auto it = M.lower_bound(-(s - ta) / 2);
        if(it != M.end()) {
//            if(i == 1 && j == 4) cout << "check : " << (it->first) << endl;
            if(abs((it->first) * 2 + s - ta) < ansv) {
                ansv = abs((it->first) * 2 + s - ta);
                anst = 2;
                ansa[1] = i; ansa[2] = j;
                ansb[1] = it->second.first; ansb[2] = it->second.second;
            }
        }
        if(it != M.begin()) {
            it--;
//            if(i == 1 && j == 4) cout << "check : " << (it->first) << " " << s << endl;
            if(abs((it->first) * 2 + s - ta) < ansv) {
                ansv = abs((it->first) * 2 + s - ta);
                anst = 2;
                ansa[1] = i; ansa[2] = j;
                ansb[1] = it->second.first; ansb[2] = it->second.second;
            }
        }
    }
    cout << ansv << endl;
    cout << anst << endl;
    for(int i = 1; i <= anst; i++) {
        cout << ansa[i] << " " << ansb[i] << endl;
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