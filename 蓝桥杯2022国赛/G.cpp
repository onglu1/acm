#include <bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
using namespace std;
const int N = 1e6 + 1009;
int n, f[N];
vector<int> se, pri;
void NO() {
    cout << -1 << endl;
    exit(0);
}
int dif[N];
void work(int pp) {
    int k = n / pp;
    for(auto p : pri) {
        if(p > n) break;
        int kp1 = ((k - 1) * pp + 1 - 1) / p + 1;
        int kp2 = k * pp / p;
        // cout << p << " " << kp1 * p << " " << kp2 * p << " " << (kp1 - 1) * p + 1 << " " << kp2 * p + 1 << endl;
        if(kp1 > kp2) continue;
        if(max((kp1 - 1) * p + 1, p + 1) >= kp2 * p + 1) continue;
        // dif[(kp1 - 1) * p + 1] += 1;
        // dif[kp2 * p + 1] -= 1;
        dif[max((kp1 - 1) * p + 1, p + 1)] += 1;
        dif[kp2 * p + 1] -= 1;
    }
}
signed main()
{
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios ::sync_with_stdio(0);
    cin.tie(0);
    f[1] = 1;
    for(int i = 2; i < N; i++) {
        if(f[i] == 0)
            pri.push_back(i);
        for(int j = 0; j < pri.size() && pri[j] * i < N; j++) {
            f[pri[j] * i] = 1;
            if(i % pri[j] == 0) break;
        }
    }
    cin >> n;
    int nt = n;
    for(int i = 2; i * i <= nt; i++) {
        if(nt % i == 0) {
            se.push_back(i);
            while(nt % i == 0) nt /= i;
        }
    }
    if(nt > 1) se.push_back(nt);
    if(se.size() == 0) NO();
    for(auto p : se) work(p);
    int ans = -1;
    for(int i = 1; i <= n + 1; i++) {
        dif[i] += dif[i - 1];
        if(dif[i] > 0) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
先分解出质因子，得到第二次，这个数量只有很少个
再枚举第一个质数是什么，这个复杂度是O(n)的
*/