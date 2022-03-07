#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 2e6 + 1009;
int n, k, l, ans[N];
int pre[N], rt[N], cnt[N];
vector<int> v[N];
int fid(int x) {
    return pre[x] == x ? x : (pre[x] = fid(pre[x]));
}
signed main() {
#ifdef LOCALCOMPILE
    auto startTime = clock();
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\ACM\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> l;
    for(int i = 1; i <= n; i++) {
        pre[i] = i;
    }
    for(int i = 1; i <= k; i++) {
        int x, y;
        cin >> x >> y;
        pre[fid(x)] = fid(y);
    }
    for(int i = 1; i <= n; i++) rt[i] = fid(i);
    for(int i = 1; i <= n; i++) {
        pre[i] = i;
    }
    for(int i = 1; i <= l; i++) {
        int x, y;
        cin >> x >> y;
        pre[fid(x)] = fid(y);
    }
    for(int i = 1; i <= n; i++) {
        v[fid(i)].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        for(auto x : v[i]) {
            cnt[rt[x]]++;
        }
        for(auto x : v[i]) {
            ans[x] = cnt[rt[x]];
        }
        for(auto x : v[i]) {
            cnt[rt[x]]--;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}