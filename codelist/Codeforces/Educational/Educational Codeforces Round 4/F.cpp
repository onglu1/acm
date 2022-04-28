//
// Created by onglu on 2022/4/27.
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
const int N = 2009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309;
int n, m, a[N], s;
int f[N], g[N], dir[N];
/*
 * f[i][0]表示停留在i，最后是往负走
 */
vector<int> b;
vector<int> pos[N];
void getTrans(int c, int s, int pv) {
    if(pv == 0x3f3f3f3f) return ;
    if(c == 1) cout << "    " << s << endl;
    if(pos[c].size() == 1) {
        if(f[pos[c][0]] > pv + min(abs(s - pos[c][0]), n - abs(s - pos[c][0]) - 1)) {
            f[pos[c][0]] = pv + min(abs(s - pos[c][0]), n - abs(s - pos[c][0]) - 1);
            g[pos[c][0]] = s;
        }
    } else {
        auto up = std::upper_bound(pos[c].begin(), pos[c].end(), s);
        if(c == 1) cout << "up = " << (*up) << endl;
        if(up != pos[c].end()) {
            if(c == 1) cout << "pv + s + n - (*up) = " << (pv + s + n - (*up)) << endl;
            if(f[*up] > pv + s + n - (*up)) {
                f[*up] = pv + s + n - (*up);
                g[*up] = s;
                dir[*up] = 0;
            }
        } else {
            if(f[pos[c][0]] > pv + s - pos[c][0]) {
                f[pos[c][0]] = pv + s - pos[c][0];
                g[pos[c][0]] = s;
                dir[*up] = 0;
            }
        }
        auto low = std::lower_bound(pos[c].begin(), pos[c].end(), s);
        if(low != pos[c].begin()) {
            low -= 1;
            if(f[*low] > pv + n - s + (*low)) {
                f[*low] = pv + n - s + (*low);
                g[*low] = s;
                dir[*low] = 1;
            }
        } else {
            low = pos[c].end() - 1;
            if(f[*low] > pv + (*low) - s) {
                f[*low] = pv + (*low) - s;
                g[*low] = s;
                dir[*low] = 1;
            }
        }
    }
}
void work() {
    cin >> n >> s;
    s -= 1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b.push_back(a[i]);
    }
    std::sort(b.begin(), b.end());
    b.resize(std::unique(b.begin(), b.end()) - b.begin());
    for(int i = 0; i < n; i++) {
        a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        pos[a[i]].push_back(i);
        pos[a[i]].push_back(i + n);
    }
    for(int i = 0; i < n; i++) pos[]

    memset(f, 0x3f, sizeof(f));
    getTrans(0, s, 0);
    cout << a[5] << " " << f[5] << endl;
    for(int i = 1; i < b.size(); i++) {
        for(auto s : pos[i - 1]) {
            getTrans(i, s, f[s]);
        }
    }
    int anspos = -1;
    for(auto s : pos[b.size() - 1]) {
        if(anspos == -1 || f[anspos] > f[s]) {
            anspos = s;
        }
    }
    cout << anspos << endl;
    cout << f[anspos] << endl;
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