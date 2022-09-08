#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 1009;
struct rec {
    int x, y, xx, yy;
};
rec a[N];
int n, L[N], R[N];
vector<int> v;
int cal() {
    int ans = 0x3f3f3f3f3f3f3f3f;
    v.clear();
    int now = 0, np, l = 0, r = n;
    for(int i = 1; i <= n; i++) {
        v.push_back(a[i].x);
        v.push_back(a[i].xx);
    }
    std::sort(v.begin(), v.end());
    v.resize(std::unique(v.begin(), v.end()) - v.begin());
    for(int i = 0; i < v.size(); i++) L[i] = R[i] = 0;
    for(int i = 1; i <= n; i++) {
        a[i].x = std::lower_bound(v.begin(), v.end(), a[i].x) - v.begin();
        a[i].xx = std::lower_bound(v.begin(), v.end(), a[i].xx) - v.begin();
        L[a[i].x] += 1;
        R[a[i].xx] += 1;
    }
    np = v[0];
    for(int i = 1; i <= n; i++) {
        now += v[a[i].x] - np;
    }
    for(int i = 0; i < v.size(); i++) {
        int x = v[i];
        ans = min(ans, now);
        now = now + l * (x - np) - r * (x - np);
        np = x;
        l += R[i];
        r -= L[i];
    }
    return ans;
}
void work() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) scanf("%lld %lld %lld %lld", &a[i].x, &a[i].y, &a[i].xx, &a[i].yy);
    int ans = cal();
    for(int i = 1; i <= n; i++) {
        swap(a[i].x, a[i].y);
        swap(a[i].xx, a[i].yy);
    }
    ans += cal();
    printf("%lld\n", ans);
    return ;
}
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
//    ios ::sync_with_stdio(0);
//    cin.tie(0);
    int Case = 1;
    scanf("%lld", &Case);
//    cin >> Case;
    while(Case--) work();
    return 0;
}