//
// Created by onglu on 2022/4/26.
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
int n, m, e;
int to[N][N];
struct node {
    int x, y;
} a[(int)5e5+1009];
int deg[N];
void work() {
    int ans = 0;
    cin >> n >> m >> e;
    for(int i = 1; i <= e; i++) {
        int x, y;
        cin >> a[i].x >> a[i].y;
        a[i].y += n;
        deg[a[i].x] += 1;
        deg[a[i].y] += 1;
        ans = max(ans, deg[a[i].x]);
        ans = max(ans, deg[a[i].y]);
    }
    for(int i = 1; i <= e; i++) {
        int c1 = 1, c2 = 1;
        while(to[a[i].x][c1]) c1++;
        while(to[a[i].y][c2]) c2++;
        to[a[i].x][c1] = a[i].y;
        to[a[i].y][c2] = a[i].x;
        if(c1 == c2) continue;
        for(int now = a[i].y, c = c2; now; now = to[now][c], c ^= c1 ^ c2) {
            swap(to[now][c1], to[now][c2]);
        }
    }
    cout << ans << endl;
    for(int i = 1; i <= e; i++) {
        for(int j = 1; j <= ans; j++) {
            if(to[a[i].x][j] == a[i].y) {
                cout << j << " ";
                break;
            }
        }
    }
    cout << endl;


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