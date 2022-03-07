#include <bits/stdc++.h>

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)

using namespace std;
const int N = 2e5 + 1009;
int n, m, h[N], tree[N * 4];
int l[N], r[N], root;
stack<int> S;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    h[0] = 0x3f3f3f3f;
    h[n + 1] = 0x3f3f3f3f;
    S.push(0);
    for(int i = 1; i <= n; i++) {
        while(S.size() && h[S.top()] < h[i]) S.pop();
        l[i] = S.top();
        S.push(i);
    }
    while(S.size()) S.pop();
    S.push(n + 1);
    for(int i = n; i >= 1; i--) {
        while(S.size() && h[S.top()] < h[i]) S.pop();
        r[i] = S.top();
        S.push(i);
    }
    for(int i = 1; i <= n; i++) {
        if(l[i] == 0 && r[i] == n + 1) {
            root = i;
        } else if(h[l[i]] < h[r[i]]) {

        }
    }
    return 0;
}
/*
 *
 */