#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;
const int N = 2e6 + 1009;
int n, m, f[N], tt[N];
long long a[N], b[N];
int ad[N], mi[N];
void update(int rt) {
    ad[rt] = max(ad[lson], ad[rson]);
    mi[rt] = max(mi[lson], mi[rson]);
}
void build(int l, int r, int rt) {
    if(l == r) {
        ad[rt] = mi[rt] = -0x3f3f3f3f;
        return ;
    }
    build(l, Mid, lson);
    build(Mid + 1, r, rson);
    update(rt);
//    cout << rt << " " << ad[rt] << " " << ad[lson] << " " << ad[rson] << endl;
}
void modify(int l, int r, int rt, int x, int fj, int j) {
    if(l == r) {
        ad[rt] = max(ad[rt], fj + j);
        mi[rt] = max(mi[rt], fj - j);
        return ;
    }
    if(x <= Mid) modify(l, Mid, lson, x, fj, j);
    else modify(Mid + 1, r, rson, x, fj, j);
    update(rt);
}
int query(int l, int r, int L, int R, int rt, int isAd) {
    if(L <= l && r <= R) {
        if(isAd) return ad[rt];
        else return mi[rt];
    }
    int ans = -0x3f3f3f3f;
    if(L <= Mid) ans = max(ans, query(l, Mid, L, R, lson, isAd));
    if(Mid <  R) ans = max(ans, query(Mid + 1, r, L, R, rson, isAd));
    return ans;
}
void work() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) a[i] += a[i - 1];
    for(int i = 1; i <= n; i++) b[i] = a[i];
    sort(b + 1, b + 1 + n);
    int tn = 0;
    for(int i = 1; i <= n; i++) {
        if(i == 1 || b[i] != b[i - 1]) {
            b[++tn] = b[i];
            tt[tn] = -0x3f3f3f3f;
        }
    }
//    for(int i = 1; i <= tn; i++) cout << b[i] << " ";
//    cout << endl;
    build(1, tn, 1);
    for(int i = 1; i <= n; i++) {
        int pos = lower_bound(b + 1, b + 1 + tn, a[i]) - b;
//        cout << "     " << pos << endl;
        if(a[i] > 0) f[i] = i;
        if(a[i] == 0) f[i] = 0;
        if(a[i] < 0) f[i] = -i;
        if(pos > 1) {
            f[i] = max(f[i], query(1, tn, 1, pos - 1, 1, 0) + i);
//            cout << "< 0 : " <<  query(1, tn, 1, pos - 1, 1, 0) << endl;
        }
        if(pos + 1 <= tn) {
            f[i] = max(f[i], query(1, tn, pos + 1, tn, 1, 1) - i);
//            cout << "> 0 : " <<  query(1, tn, pos + 1, tn, 1, 1) << endl;
        }
        f[i] = max(f[i], tt[pos]);
        tt[pos] = max(tt[pos], f[i]);
        modify(1, tn, 1, pos, f[i], i);
//        cout << f[i] << endl;
    }
    cout << f[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
    cin >> Case;
    while (Case--) work();
    return 0;
}