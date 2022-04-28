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
//#define int long long
using namespace std;
//const int N = 2e6 + 1009;
const int N = 2e6 + 1009;
//const int N = 5009;
//const int N = 309
int dx[] = {-1, -1, 1, 1};
int dy[] = {1, -1, 1, -1};
int n, m, a[N], cntd[N];
vector<int> v[N];
map<pair<int, int>, int> M;
int getnum(int x, int y, int len) {
    int sum = 0;
    for(int i = max(x - len, 1); i <= min(N - 1, x + len); i++) {
        auto itl = std::lower_bound(v[i].begin(), v[i].end(), y - len);
        auto itr = std::upper_bound(v[i].begin(), v[i].end(), y + len);
        sum += itr - itl;
    }
    return sum;
}
void get(int x, int y) {
    int l = 1, r = 500;
    while(l <= r) {
        int cnt = getnum(x, y, Mid);
        if(cnt < cntd[Mid]) r = Mid - 1;
        else l = Mid + 1;
    }
    int ox = (x + y) / 2;
    int oy = (x - y) / 2;
    for(int i = 1; i <= l; i++) {
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
        v[tx].push_back(ty);
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
    for(int i = -1000; i <= 1000; i++) {
        for(int j = -1000; j <= 1000; j++) {
            cntd[abs(i) + abs(j)]++;
        }
    }
    work();
    return 0;
}