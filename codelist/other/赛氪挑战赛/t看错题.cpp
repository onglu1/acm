#include <bits/stdc++.h>
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define rep(i, x, y) for(int i = 1; i <= n; i ++)
using namespace std;
const int N = 2e6 + 1009;
int a[N], sz[N], dep[N];
long long ans = 0;
long long build(int l, int r, int rt)
{
    if(l == r)
    {
        sz[rt] = 1;
        dep[rt] = 1;
        ans += a[l];
        return a[l];
    }
    int mid = l + r >> 1;
    long long val = build(l, mid, ls) + build(mid + 1, r, rs);
    dep[rt] = dep[ls] + 1;
    sz[rt] = sz[ls] + sz[rs];
    ans += 1LL * sz[rt] * val;
    return val;
}
long long modify(int l, int r, int L, int R, int rt, int x)
{
    if(L <= l && r <= R)
    {
        ans += 1LL * sz[rt] * ((1 << (dep[rt])) - 1) * x;
        return ((1 << (dep[rt] - 1))) * x;
    }
    long long val = 0;
    int mid = l + r >> 1;
    if(L <= mid) val += modify(l, mid, L, R, ls, x);
    if(mid <  R) val += modify(mid + 1, r, L, R, rs, x);
    ans += 1LL * sz[rt] * val;
    return val;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    rep(i, 1, n) scanf("%d", &a[i]);

    build(1, n, 1);
    rep(i, 1, m)
    {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        modify(1, n, l, r, 1, x);
        printf("%lld\n", ans);
    }
    return 0;
}