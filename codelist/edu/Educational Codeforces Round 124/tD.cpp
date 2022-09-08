//
// Created by onglu on 2022/3/10.
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
int dx[] = {-1, -1, 1, 1};
int dy[] = {1, -1, 1, -1};
int n, m, a[N], cntd[N];
vector<int> v[N];
map<pair<int, int>, int> M;
int add(int x, int y) {
    for( ; x < N; x += x & -x)
        v[x].push_back(y);
}
int query(int l, int x, int y) {
    if(l <= 0) return 0;
    if(l >= N) l = N - 1;
    int sum = 0;
    for( ; l; l -= l & -l) {
        auto itl = std::lower_bound(v[l].begin(), v[l].end(), x);
        auto itr = std::upper_bound(v[l].begin(), v[l].end(), y);
        sum += itr - itl;
    }
    return sum;
}
int getnum(int l, int r, int x, int y) {
    return query(r, x, y) - query(l - 1, x, y);
}
int getnum(int x, int y, int len) {
    return getnum(x - len, x + len, y - len, y + len);
}
void get(int x, int y) {
    int l = 1, r = 600;
    while(l <= r) {
        int cnt = getnum(x, y, Mid);
        if(cnt < 2 * Mid * (Mid + 1) + 1) r = Mid - 1;
        else l = Mid + 1;
    }
    int ox = (x + y) / 2;
    int oy = (x - y) / 2;
    for(int i = 0; i <= l; i++) {
        int j = l - i;
        for(int p = 0; p < 4; p++) {
            int tx = ox + dx[p] * i;
            int ty = oy + dy[p] * j;
            if(!M.count({tx, ty})) {
                cout << tx << " " << ty << endl;
                return ;
            }
        }
    }
}
vector<pair<int, int> > tmp;
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        int tx = x + y;
        int ty = x - y;
        add(tx, ty);
        tmp.emplace_back(x, y);
        M[{x, y}] = 1;
    }
    for(int i = 1; i < N; i++) {
        sort(all(v[i]));
    }
    for(auto x : tmp) {
        get(x.first + x.second, x.first - x.second);
    }
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