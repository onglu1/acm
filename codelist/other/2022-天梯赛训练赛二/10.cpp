//
// Created by onglu on 2022/3/9.
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
//const int N = 1e4 + 1009;
const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N], pri[N];
int l, r, in[N], to[N], num[N];
int good[N];
int nxt(int x) {
    int p = 0;
    while(x) {
        p += (x % 10) * (x % 10);
        x /= 10;
    }
    return p;
}
int isgood(int x) {
    if(good[x] != -1) return good[x];
    int vis[N] = {0};
    int cnt = 0, tx = x;
    while(!vis[x] && x != 1) {
        vis[x] = 1;
        x = nxt(x);
        cnt++;
    }
    num[tx] = cnt;
    if(x == 1) return good[tx] = 1;
    else return good[tx] = 0;
}
void get(int x) {
    int vis[N] = {0};
    int cnt = 0, tx = x;
    x = nxt(x);
    while(x != 1) {
        if(in[x] == 1) break;
        in[x] = 1;
        x = nxt(x);
    }
}
int ok = 1;
void work() {
    pri[1] = 1;
    for(int i = 2; i < N; i++) if(!pri[i]) {
            for(int j = i + i; j < N; j += i) {
                pri[j] = 1;
            }
        }
    memset(good, -1, sizeof good);
    for(int i = 1; i < N; i++) pri[i] = !pri[i];
    cin >> l >> r;
    for(int i = l; i <= r; i++) if(isgood(i)){
            get(i);
        }
    for(int i = l; i <= r; i++) {
        if(isgood(i) && in[i] == 0) {
            cout << i << " " << (num[i]) * (pri[i] ? 2 : 1) << endl;
            ok = 0;
        }
    }
    if(ok) cout << "SAD" << endl;
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
//    check(19);
    work();
    return 0;
}