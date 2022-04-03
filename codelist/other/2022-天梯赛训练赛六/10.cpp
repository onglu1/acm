//
// Created by onglu on 2022/3/23.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
//#define int long long
using namespace std;
const int N = 2e6 + 1009;
//const int N = 2e5 + 1009;
//const int N = 5009;
//const int N = 309
int n, m, a[N];
int pe2[N];
double p1[N];
double pc2[N];
vector<pair<int, double> > ans1;
void print(vector<pair<int, double> > &ans1) {
    if(ans1.size() == 0) {
        printf("0 0 0.0\n");
        return ;
    }
    printf("%d", ans1.size());
    for(auto x : ans1) {
        printf(" %d %.1f", x.first, x.second);
    }
    printf("\n");
}
void work() {
    int maxn = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int e, c;
        cin >> e >> c;
        p1[e] = c;
        maxn = max(maxn, e);
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        cin >> pe2[i] >> pc2[i];
    }
    for(int i = maxn; i >= pe2[1]; i--) {
        double t = 1.0 * p1[i] / pc2[1];
        for(int j = 1; j <= m; j++) {
            p1[i - (pe2[1] - pe2[j])] -= t * pc2[j];
        }
        if(fabs(t * 100) < 5) continue;
        ans1.emplace_back(i - pe2[1], t);
    }
    print(ans1);
    ans1.resize(0);
    for(int i = pe2[1] - 1; i >= 0; i--) {
        if(fabs(p1[i] * 100) < 5) continue;
        ans1.emplace_back(i, p1[i]);
    }
    print(ans1);
}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//  cin >> Case;
    while (Case--) work();
    return 0;
}