//
// Created by onglu on 2022/3/19.
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
const int N = 2e5 + 1009;
map<string, int> M;
struct task {
    int id, cnt, maxn;
    int inc;
} a[N];
vector<int> v[N];
int n, m;
int q;
int ans = 0;
int scr[N], maxcnt;
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        M[s] = i;
        cin >> scr[M[s]];
        a[i].id = i;
    }
    cin >> q;
    while(q--) {
        string s;
        int x;
        cin >> s >> x;
        a[M[s]].maxn = max(a[M[s]].maxn, x);
        a[M[s]].cnt++;
        v[M[s]].push_back(x);
        maxcnt = max(maxcnt, a[M[s]].cnt);
    }
    for(int i = 1; i <= n; i++) {
        sort(all(v[i]));
    }
    for(int i = 1; i <= n; i++) {
        if(a[i].maxn < scr[i]) {
            ans += scr[i] * a[i].cnt;
            a[n].id = i;
            swap(a[n], a[i]);
            swap(scr[i], scr[n]);
            n--;
            i--;
        } else {
            for(auto x : v[i]) {
                if(x < a[i].maxn) {
                    ans += a[i].maxn;
                    a[i].inc++;
                } else {
                    a[i].inc += x;
                }
            }
            m -= a[i].maxn - scr[i];
            scr[i] = a[i].maxn;
        }
    }
    if(m < 0) {
        cout << 0 << endl;
        return ;
    }
    sort(a + 1, a + 1 + n, [](const task &a, const task &b) {
        return a.inc > b.inc;
    });
    for(int i = 1; i <= n && m > 0; i++) {
        if(a[i].inc >= maxcnt) {
            ans += a[i].inc;
            m -= 1;
        } else {
            break;
        }
    }
    ans += m * maxcnt;
    cout << ans << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    work();
    return 0;
}