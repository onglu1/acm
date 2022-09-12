#include <bits/stdc++.h>
using namespace std;
const int mod1 = 1019260817, mod2 = 1000000009, base1 = 546365, base2 = 43534543, mod = 1000000007;
int power(int a, int b) {
    long long res = a, ans = 1;
    for (; b; b >>= 1, res = res * res % mod) if (b & 1) ans = ans * res % mod;
    return ans;
}
char s[100010];
long long a[100010], b[100010];
int n, m, k;
int pw2[100010];
struct node {
    int l, r, id;
} q[500010];
int ans[500010];
const int S = 150;
void Add(int &x, int y) { if ((x += y) >= mod) x -= mod; }
int l = 1, r = 0, cans = 0;
int buc[100010];
void add(int x) {
    Add(cans, pw2[buc[a[x]]++]);
}
void del(int x) {
    Add(cans, mod - pw2[--buc[a[x]]]);
}
int main() {
    scanf("%s", s + 1);
    scanf("%d%d", &k, &m);
    if (k == 0) {
        for (int i = 1; i <= m; i++) puts("1");
        return 0;
    }
    n = strlen(s + 1);
    pw2[0] = 1;
    for (int i = 1; i <= n; i++) pw2[i] = 2 * pw2[i - 1] % mod;
    int A = 0, B = 0;
    int pb1 = mod1 - 1, pb2 = mod2 - 1;
    for (int i = 1; i <= k; i++) pb1 = 1ll * pb1 * base1 % mod1, pb2 = 1ll * pb2 * base2 % mod2;
    for (int i = n; i > 0; i--) {
        A = (1ll * A * base1 + s[i]) % mod1;
        B = (1ll * B * base2 + s[i]) % mod2;
        if (i + k <= n) {
            A = (A + 1ll * s[i + k] * pb1) % mod1;
            B = (B + 1ll * s[i + k] * pb2) % mod2;
        }
        b[i] = a[i] = (long long)A << 31 | B;
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &q[i].l, &q[i].r);
        q[i].id = i;
    }
    sort(q + 1, q + 1 + m, [](node a, node b) {
        return a.l / S == b.l / S ? a.l / S % 2 ? a.r < b.r : a.r > b.r : a.l < b.l;
    });
    for (int i = 1; i <= m; i++) {
        while (r < q[i].r) add(++r);
        while (l > q[i].l) add(--l);
        while (r > q[i].r) del(r--);
        while (l < q[i].l) del(l++);
        // cerr << q[i].id << ' ' << cans << ' ' << l << ' ' << r << endl;
        ans[q[i].id] = 1ll * (cans + mod - (r - l + 1)) * power((mod + 1) / 2, r - l + 1) % mod;
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}
