//
// Created by onglu on 2022/2/25.
//

#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, pre[N], nxt[N];
int val[N], tot = 0;
void work() {
    cin >> n;
    int head = 1, now = 1;
    tot = 1;
    val[1] = pre[1] = nxt[1] = 0;
    for(int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        val[++tot] = i;
        if(c == 'L') {
            pre[tot] = pre[now];
            nxt[tot] = now;
            nxt[pre[now]] = tot;
            pre[now] = tot;
            now = tot;
            if(pre[now] == 0) head = now;
        } else {
            pre[tot] = now;
            nxt[tot] = nxt[now];
            pre[nxt[now]] = tot;
            nxt[now] = tot;
            now = tot;
        }
    }
    for(int i = head; i; i = nxt[i]) {
        cout << val[i] << " ";
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
    work();
    return 0;
}