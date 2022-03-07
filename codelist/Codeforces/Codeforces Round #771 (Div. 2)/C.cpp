#include <bits/stdc++.h>

#define Mid ((l + r) / 2)
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 1e5 + 1009;
int n, m, a[N], pos[N], pre[N], siz[N];
vector<int> v;
int fid(int x) {
    return pre[x] == x ? x : pre[x];
};
void work() {
    cin >> n;
    v.clear();
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) pos[a[i]] = i;
    for(int i = 1; i <= n; i++) pre[i] = i, siz[i] = 0;
    int now = 0, cnt = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(pos[i] > now) {
            for(int j = now + 1; j <= pos[i]; j++) {
                pre[fid(j)] = fid(i);
                siz[fid(i)] += 1;
            }
            now = pos[i];
            int ns = 0;
            for(int j = (int)v.size() - 1; j >= 0; j--) {
                ns += siz[fid(v[j])];
                siz[fid(v[j])] = 0;
                v.pop_back();
            }
            siz[fid(i)] += ns;
            v.push_back(i);
        }
        siz[fid(i)] -= 1;
        if(siz[fid(i)] == 0) ans++;
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
    int Case = 0;
    cin >> Case;
    while (Case--) work();
#ifdef LOCALCOMPILE
    cout << "The run time is: " <<(double)(clock() - startTime) * 1000 / CLOCKS_PER_SEC << "ms" << endl;
#endif
    return 0;
}