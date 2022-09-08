//
// Created by onglu on 2022/4/28.
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
int n, m, a[N], pre[N], siz[N];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
char c[1009][1009];
int pos(int x, int y) {
    return (x - 1) * m + y;
}

int fid(int x) {
    return pre[x] == x ? x : (pre[x] = fid(pre[x]));
}
int fid(int x, int y) {
    return fid(pos(x, y));
}
void work() {
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++) pre[i] = i, siz[i] = 1;
//    for(int i = 1; i <= n; i++) {
//        for(int j = 1; j <= m; j++) {
//            cout << pos(i, j) << " ";
//            cout << siz[fid(i, j)] % 10;
//        }
//        cout << endl;
//    }
//    cout << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if(c[i][j] == '.') {
                if(i > 1 && c[i - 1][j] == '.') {
                    siz[fid(i - 1, j)] += siz[fid(i, j)];
                    pre[fid(i, j)] = fid(i - 1, j);
                }
                if(j > 1 && c[i][j - 1] == '.' && fid(i, j) != fid(i, j - 1)) {
                    siz[fid(i, j - 1)] += siz[fid(i, j)];
                    pre[fid(i, j)] = fid(i, j - 1);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(c[i][j] == '*'){
            set<int> S;
            int ans = 0;
            for(int d = 0; d < 4; d++) {
                int xx = i + dx[d];
                int yy = j + dy[d];
                if(xx <= 0 || yy <= 0 || xx > n || yy > m) continue;
                if(c[xx][yy] != '.') continue;
                if(S.count(fid(xx, yy))) continue;
                ans += siz[fid(xx, yy)];
                S.insert(fid(xx, yy));
            }
            cout << (ans + 1) % 10;
        } else {
            cout << ".";
        }
        cout << endl;
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