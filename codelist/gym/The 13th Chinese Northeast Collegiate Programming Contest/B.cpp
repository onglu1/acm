//
// Created by onglu on 2022/5/14.
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
int n, m;
struct node {
    int id, l, used;
    vector<int> a;
} t[N];
void work() {
    int maxn = 0;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        t[i].used = 0;
        t[i].id = i;
        t[i].a.clear();
        cin >> t[i].l;
    }
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        t[y].a.push_back(x);
    }
    for(int i = 1; i <= m; i++)
        std::sort(t[i].a.begin(), t[i].a.end(), [](const int &a, const int &b) { return a > b; } );
    for(int i = 1; i <= m; i++) {
        maxn = max(maxn, (int)t[i].a.size());
    }
    sort(t + 1, t + 1 + m, [](const node &a, const node &b) {
        return a.l < b.l;
    });
    list<node> l(t + 1, t + 1 + m);
    // for(auto it : l) {
    //     cout << it.id << " " << it.l;
    //     for(auto p : it.a) cout << " " << p ;
    //     cout << endl;
    // }
    // cout << endl;
    int ma = -1, mb = -1;
    int nowa = 0;
    for(int i = 1; i <= maxn; i++) {
        auto it = l.begin();
        for( ; it != l.end(); ) {
            if(it->l > i) break;
            for(int j = it->used; j < min(i, (int)it->a.size()); j++) {
                nowa += it->a[j];
            }
            it->used = min(i, (int)it->a.size());
            if(it->used == it->a.size()) {
                auto save = it;
                it++;
                l.erase(save);
            } else {
                it++;
            }
        }
        int ta = nowa, tb = i;
        int t = __gcd(ta, tb);
        ta /= t; tb /= t;
        if(ma == -1 && mb == -1) {
            ma = ta;
            mb = tb;
        } else if(ma * tb < ta * mb){
            ma = ta;
            mb = tb;
        }
    }
    cout << ma << "/" << mb << endl;
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