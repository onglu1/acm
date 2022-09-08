//
// Created by onglu on 2022/5/6.
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
int c[27];
string s;
void work() {
    cin >> n;
    cin >> s;
    memset(c, 0, sizeof(c));
    cin >> m;
    for(int i = 1; i <= m; i++) {
        char t;
        cin >> t;
        c[t - 'a'] = 1;
    }
    vector<int> v;
    int now = 0, maxn = 0;
    for(int i = 0; i < n; i++) {
        if(c[s[i] - 'a']) {
            v.push_back(now);
            maxn = max(maxn, now);
            now = 0;
        } else {
            now += 1;
        }
    }
    if(!v.size()) cout << 0 << endl;
    else {
        for(int i = 0; i < v.size(); i++) if(v[i] == maxn) {
            if(i != 0) {
                cout << maxn + 1 << endl;
                return ;
            }
        }
        cout << maxn << endl;
    }
//    int cnt = 0, maxn = 0, now = 0, p = 1;
//    for(int i = 0; i < n; i++) {
//        now += 1;
//        if(c[s[i] - 'a']) {
//            if(now > maxn) {
//                if(cnt)
//                    p = 0;
//                maxn = now;
//            }
//            cnt++;
//            now = 0;
//        }
//    }
//    int ans = 0;
//    if(cnt == 0) cout << 0 << endl;
//    else
//        cout << (maxn - 1) + p << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    cin >> Case;
    while (Case--) work();
    return 0;
}