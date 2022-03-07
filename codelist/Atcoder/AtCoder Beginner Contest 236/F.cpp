#include <bits/stdc++.h>
#define int long long
#define endl ('\n')
#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, m, rep[20];
struct node {
    int x, v;
} a[N];
int ins(int x) {
    for(int i = n - 1; i >= 0; i--) if(x & (1 << i)) {
        if(rep[i]) x ^= rep[i];
        else {
            rep[i] = x;
            return 1;
        }
    }
    return 0;
}
void work() {
    cin >> n;
    for(int i = 1; i < (1 << n); i++) {
        a[i].x = i;
        cin >> a[i].v;
    }
    sort(a + 1, a + (1 << n), [](const node &a, const node b) {
        return a.v < b.v;
    });
    int ans = 0;
    for(int i = 0; i < n; i++) rep[i] = 0;
    for(int i = 1; i < (1 << n); i++) {
        if(ins(a[i].x)) {
            ans += a[i].v;
        }
    }
    cout << ans << endl;
}

signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int Case = 1;
    while (Case--) work();
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}