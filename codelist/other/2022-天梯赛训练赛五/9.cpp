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
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N], vis[N];
int pre[N];
vector<int> ver[N];
int ra[N];
int fid(int x) {
    return pre[x] == x ? x : (pre[x] = fid(pre[x]));
}
void work() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++) pre[i] = i;
    for(int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        ver[x].push_back(y);
        ver[y].push_back(x);
    }
    int k;
    scanf("%d", &k);
    for(int i = 0; i < n; i++) vis[i] = 1;
    for(int i = 1; i <= k; i++) {
        scanf("%d", &a[i]);
        vis[a[i]] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(auto y : ver[i]) {
            if(vis[i] && vis[y]) {
                pre[fid(i)] = fid(y);
            }
        }
    }
    for(int t = k; t > 0; t--) {
        int x = a[t];
        int meg = 0;
        vis[x] = 1;
        for(auto y : ver[x]) {
            if(vis[x] && vis[y]) {
                if(fid(x) != fid(y)) meg++;
                pre[fid(x)] = fid(y);
            }
        }
        ra[t] = meg > 1;
    }
    for(int i = 1; i <= k; i++) {
        if(ra[i]) printf("Red Alert: City %d is lost!\n", a[i]);
        else printf("City %d is lost.\n", a[i]);
    }
    if(k == n) printf("Game Over.\n");

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