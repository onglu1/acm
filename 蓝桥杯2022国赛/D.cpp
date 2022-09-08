#include <bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
const int N = 2e5 + 1009;
int n, a[N], tree[N];
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}
void build(int l, int r, int rt) {
    if(l == r) {
        tree[rt] = a[l];
        return ;
    }
    build(l, Mid, lson); build(Mid + 1, r, rson);
    tree[rt] = gcd(tree[lson], tree[rson]);
}
int query(int l, int r, int L, int R, int rt) {
    if(L <= l && r <= R) return tree[rt];
    if(R <= Mid) return query(l, Mid, L, R, lson);
    else if(L > Mid) return query(Mid + 1, r, L, R, rson);
    else return gcd(query(l, Mid, L, R, lson), query(Mid + 1, r, L, R, rson));
}
int query(int l, int r) {
    return query(1, n, l, r, 1);
}
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios ::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, n, 1);
    int ans = n;
    if(query(1, n) != 1) {
        cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        cnt += a[i] == 1;
    }
    if(cnt != 0) {
        cout << n - cnt << endl;
        return 0;
    }
    for(int i = 1; i <= n; i++) {
        int l = i, r = n;
        while(l <= r) {
            if(query(i, Mid) != 1) l = Mid + 1;
            else r = Mid - 1;
        }
        if(l <= n) {
            ans = min(ans, l - i + 1);
        }
    }
    cout << ans - 1 + n - 1 << endl;
    return 0;
}
/*
* 最短的区间，使得区间gcd=1
*
*/