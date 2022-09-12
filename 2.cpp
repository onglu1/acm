#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod1 = 998244353, mod2 = 1000000009, base1 = 1e5 + 7, base2 = 1e5 + 9, mod = 1000000007;
const int N = 5e5 + 10;
int qpow(ll x, ll times)
{
    int res = 1;
    while(times)
    {
        if(times & 1) res = 1LL * res * x % mod;
        x = 1LL * x * x % mod;
        times >>= 1;
    }
    return res;
}
char s[N];
ll a[N], b[N];
int n, m, k, pw2[N];
struct Node
{
    int l, r, id;
} q[N];
int ans[N];
const int S = 300;
int l = 1, r = 0, cans = 0;
int md[N];
int pp = mod1 - 1, bb = mod2 - 1;
void init(int n)
{
    pw2[0] = 1;
    for (int i = 1; i <= n; i ++) pw2[i] = 2 * pw2[i - 1] % mod;
}

bool cmp(Node a, Node b)
{
    return a.l / S == b.l / S ? a.l / S % 2 ? a.r < b.r : a.r > b.r : a.l < b.l;
}
int main()
{
    init(100000);
    scanf("%s", s + 1);
    scanf("%d%d", &k, &m);
    for (int i = 1; i <= m; i ++) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
    n = strlen(s + 1);
    int A = 0, B = 0;
    for (int i = 1; i <= k; i ++) pp = 1ll * pp * base1 % mod1, bb = 1ll * bb * base2 % mod2;
    for (int i = n; i > 0; i --)
    {
        A = (1ll * A * base1 + s[i]) % mod1;
        B = (1ll * B * base2 + s[i]) % mod2;
        if (i + k <= n)
        {
            A = (A + 1ll * s[i + k] * pp) % mod1;
            B = (B + 1ll * s[i + k] * bb) % mod2;
        }
        b[i] = a[i] = (long long)A << 31 | B;
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i ++) a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    sort(q + 1, q + 1 + m, cmp);
    for (int i = 1; i <= m; i ++)
    {
        while (r < q[i].r) (cans += pw2[md[a[++ r]] ++]) %= mod;
        while (l > q[i].l) (cans += pw2[md[a[-- l]] ++]) %= mod;
        while (r > q[i].r) (cans += mod - pw2[--md[a[r --]]] + mod) %= mod;
        while (l < q[i].l) (cans += mod - pw2[--md[a[l ++]]] + mod) %= mod;
        ans[q[i].id] = 1ll * (cans + mod - (r - l + 1)) * qpow((mod + 1) / 2, r - l + 1) % mod;
    }
    if (k == 0)
    {
        for (int i = 1; i <= m; i ++) puts("1");
        return 0;
    }
    for (int i = 1; i <= m; i ++) printf("%d\n", ans[i]);
}